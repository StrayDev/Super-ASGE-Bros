/*******************************************************************************
 * @file Logger.hpp
 * https://gist.github.com/kevinkreiser/39f2e39273c625d96790
 *
 * This is a thread safe cross platform logger. It's versatile in that it
 * can be extended to support additional logger's i.e. xml, json as well as
 * coming with a std::cout and basic file logger.
 *
 * It works well enough, however, logging can have a negative impact on
 * performance, so choose a log level that best fits the build you're producing.
 * For example a release build may disable all logging to reduce the impact
 * logging would have.
 *
 * -DLOGGING_LEVEL_NONE to disable logging OR
 * target_compile_definitions(GameEngine PUBLIC LOGGING_LEVEL_NONE)
 *
 * The default logging uses cout with colours. You must configure alternatives
 * logging::configure({ {"type", "file"}, {"file_name", "test.log"}, {"reopen_interval", "1"} });
 *
 * Some predefined logging functions/levels are provided
 * logging::ERROR("logging error");
 * logging::WARN("logging warning");
 * logging::INFO(logging info)
 * logging::DEBUG(logging debug)
 * logging::TRACE(logging trace)
 * logging::log(logging::timestamp() + " \x1b[35;1m[CUSTOM]\x1b[0m " + "msg");
 *
 ******************************************************************************/


#ifndef __LOGGING_HPP__
#define __LOGGING_HPP__

#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <mutex>
#include <unordered_map>
#include <memory>
#include <chrono>
#include <ctime>
#include <cstdlib>

/// \namespace Logging
/// \brief Use to log messages
/// \details The universal logging system and its functionality resides here
namespace Logging
{
  /// The logging level to use
  /// This will filter out any messages below the current log level
  enum class LogLevel : uint8_t
  {
    TRACE  = 0, /// Enum value TRACE
    DEBUG  = 1, /// Enum value DEBUG
    INFO   = 2, /// Enum value INFO
    WARN   = 3, /// Enum value WARN
    ERRORS = 4, /// Enum value ERRORS
    NONE   = 5  /// Enum value NONE
  };

  /// Hash used in unordered map
  struct enum_hasher
  {
    template<typename T>
    std::size_t operator()(T t) const
    {
      return static_cast<std::size_t>(t);
    }
  };

  // all, something in between, none or default to info
#if defined(LOGGING_LEVEL_ALL) || defined(LOGGING_LEVEL_TRACE)
  constexpr const LogLevel LOG_LEVEL_CUTOFF = LogLevel::TRACE;
#elif defined(LOGGING_LEVEL_DEBUG)
  constexpr LogLevel LOG_LEVEL_CUTOFF = LogLevel::DEBUG;
#elif defined(LOGGING_LEVEL_WARN)
  constexpr LogLevel LOG_LEVEL_CUTOFF = LogLevel::WARN;
  #elif defined(LOGGING_LEVEL_ERROR)
  constexpr LogLevel LOG_LEVEL_CUTOFF = LogLevel::ERRORS;
  #elif defined(LOGGING_LEVEL_NONE)
  constexpr LogLevel LOG_LEVEL_CUTOFF = LogLevel::NONE;
  #else
  constexpr LogLevel LOG_LEVEL_CUTOFF = LogLevel::INFO;
#endif

  /// @brief Creates a timestamp using GMT
  /// @return returns formatted to: 'year/mo/dy hr:mn:sc.xxxxxx'
  inline std::string timestamp()
  {
    // get the time
    std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
    std::time_t tt = std::chrono::system_clock::to_time_t(tp);
    std::tm gmt = *gmtime(&tt);
    //gmtime_r(&tt, &gmt);

    using sec_t = std::chrono::duration<double>;
    std::chrono::duration<double> fractional_seconds =
      (tp - std::chrono::system_clock::from_time_t(tt)) +
      std::chrono::seconds(gmt.tm_sec);

    // format the string
    std::string buffer("year/mo/dy hr:mn:sc.xxxxxx");

    sprintf(
      &buffer.front(),
      "%04d/%02d/%02d %02d:%02d:%09.6f",
      gmt.tm_year + 1900,
      gmt.tm_mon + 1,
      gmt.tm_mday,
      gmt.tm_hour,
      gmt.tm_min,
      fractional_seconds.count());

    return buffer;
  }

  class LoggerBase;
  using LoggingConfig_t  = std::unordered_map<std::string, std::string>;
  using LoggerCreator    = LoggerBase*(*)(const LoggingConfig_t&);

  /// \brief A factory that can create loggers (that derive from 'logger')
  /// via function pointers this way you could make your own logger that sends
  /// log messages to who knows where
  class LoggerFactory : public std::unordered_map<std::string, LoggerCreator>
  {
   public:
    LoggerBase* produce(const LoggingConfig_t& config) const;
  };

  /// \brief logger base class
  /// \details not pure virtual so you can use as a null logger if you want
  class LoggerBase
  {
   public:
    /// \brief Log level mappings to plain-text headers
    const std::unordered_map<LogLevel, std::string, enum_hasher> uncolored{
      { LogLevel::ERRORS, " [ERROR] " },
      { LogLevel::WARN, " [WARN] " },
      { LogLevel::INFO, " [INFO] " },
      { LogLevel::DEBUG, " [DEBUG] " },
      { LogLevel::TRACE, " [TRACE] " }
    };

    /// \brief Log level mappings to coloured headers
    const std::unordered_map<LogLevel, std::string, enum_hasher> colored{
      { LogLevel::ERRORS, " \x1b[31;1m[ERROR]\x1b[0m " },
      { LogLevel::WARN, " \x1b[33;1m[WARN]\x1b[0m " },
      { LogLevel::INFO, " \x1b[32;1m[INFO]\x1b[0m " },
      { LogLevel::DEBUG, " \x1b[34;1m[DEBUG]\x1b[0m " },
      { LogLevel::TRACE, " \x1b[37;1m[TRACE]\x1b[0m " }
    };


   public:
    LoggerBase() = delete;
    explicit LoggerBase(const LoggingConfig_t& config){};
    virtual ~LoggerBase() = default;
    virtual void log(const std::string&, const LogLevel){};
    virtual void log(const std::string&){};

   protected:
    std::mutex lock;
  };

  /// \brief logger that writes to standard out
  class StdOutLogger : public LoggerBase
  {
   public:
    StdOutLogger() = delete;
    explicit StdOutLogger(const LoggingConfig_t& config);
    void log(const std::string& message, LogLevel level) override;
    void log(const std::string& message) override;

   protected:
    const std::unordered_map<LogLevel, std::string, enum_hasher> levels;
  };

  /// \brief logger that writes to file
  class FileLogger : public LoggerBase
  {
   public:
    FileLogger() = delete;
    explicit FileLogger(const LoggingConfig_t& config);
    void log(const std::string& message, LogLevel level) override;
    void log(const std::string& message) override;

   protected:
    void reopen();
    std::string file_name;
    std::ofstream file;
    std::chrono::seconds reopen_interval{};
    std::chrono::system_clock::time_point last_reopen;
  };

  /// \brief statically get a factory
  inline LoggerFactory& getFactory()
  {
    static LoggerFactory factory_singleton{};
    return factory_singleton;
  }

  /// \brief register your custom loggers here
  inline bool
  RegisterLogger(const std::string& name, LoggerCreator function_ptr)
  {
    auto success = getFactory().emplace(name, function_ptr);
    return success.second;
  }

  /// \brief get at the singleton
  inline LoggerBase& getLogger(
#ifdef WIN32
    const LoggingConfig_t& config = { { "type", "std_out" }, { "uncolored", "" } })
#else
  const LoggingConfig_t& config = { { "type", "std_out" }, { "color", "" } })
#endif
  {
    static std::unique_ptr<LoggerBase> singleton(getFactory().produce(config));
    return *singleton;
  }

  /// \brief configure the singleton (once only)
  inline void configure(const LoggingConfig_t& config)
  { getLogger(config);
  }

  /// \brief checks to see if log level threshold is met
  /// \param level the requested log level
  inline bool logable(LogLevel level)
  {
    return !(level < LOG_LEVEL_CUTOFF);
  }

  /// statically log manually without the macros below
  /// \param message
  /// \param level
  inline void log(const std::string& message, const LogLevel level)
  {
    getLogger().log(message, level);
  }

  /// statically log manually without a level or maybe with a custom one
  /// \param message
  inline void log(const std::string& message)
  {
    getLogger().log(message);
  }

  /// logs the message at TRACE level
  /// \param message
  /// \see LogLevel::TRACE
  inline void TRACE(const std::string& message)
  {
    if (logable(LogLevel::TRACE))
    {
      getLogger().log(message, LogLevel::TRACE);
    }
  }

  /// Logs the message as informational
  /// \param message
  /// \see LogLevel::INFO
  inline void INFO(const std::string& message)
  {
    if (logable(LogLevel::INFO))
    {
      getLogger().log(message, LogLevel::INFO);
    }
  }

  /// Logs the message for debug use
  /// \param message
  /// \see LogLevel::DEBUG
  inline void DEBUG(const std::string& message)
  {
    if (logable(LogLevel::DEBUG))
    {
      getLogger().log(message, LogLevel::DEBUG);
    }
  }

  /// Logs the message as a warning
  /// \param message
  /// \see LogLevel::WARN
  inline void WARN(const std::string& message)
  {
    if (logable(LogLevel::WARN))
    {
      getLogger().log(message, LogLevel::WARN);
    }
  }

  /// Logs the message at ERROR level
  /// \param message
  /// \see LogLevel::ERROR
  inline void ERRORS(const std::string& message)
  {
    if (logable(LogLevel::ERRORS))
    {
      getLogger().log(message, LogLevel::ERRORS);
    }
  }

  /// \brief registers the null logger
  const bool logger_registered =
    RegisterLogger("", [](const LoggingConfig_t& config) {
      auto l = new LoggerBase(config);
      return l;
    });

  /// \brief registers the std out logger
  const bool std_out_logger_registered =
    RegisterLogger("std_out", [](const LoggingConfig_t& config) {
      LoggerBase* l = new StdOutLogger(config);
      return l;
    });

  /// \brief registers the file logger
  const bool file_logger_registered =
    RegisterLogger("file", [](const LoggingConfig_t& config) {
      LoggerBase* l = new FileLogger(config);
      return l;
    });
}

#endif //__LOGGING_HPP__