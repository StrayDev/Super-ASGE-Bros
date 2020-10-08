#------------------------------------------------------------------------------
# Sets up the build global build options
#------------------------------------------------------------------------------
include(build/platform)
include(build/lto)

if (CMAKE_VERSION VERSION_GREATER_EQUAL 3.14.0)
    include(CheckPIESupported)
    check_pie_supported()

    if(NOT CMAKE_CXX_LINK_PIE_SUPPORTED)
        message(STATUS "POSITION INDEPENDENT CODE: \t OFF")
    else()
        message(STATUS "POSITION INDEPENDENT CODE: \t ON")
    endif()
endif()

include(build/goldlink)

if ( CMAKE_COMPILER_IS_GNUCC )
    list(APPEND BUILD_FLAGS_FOR_CXX
            "-Wall" "-Wextra" "-Wshadow" "-Wnon-virtual-dtor"
            "-Wold-style-cast" "-Wunused" "-pedantic"
            "-Woverloaded-virtual" "-Wpedantic" "-Wconversion"
            "-Wduplicated-cond" "-Wduplicated-branches" "-Wlogical-op"
            "-Wnull-dereference" "-Wuseless-cast"
            "-Wno-unused-parameter" "-Werror")

    set(APPEND DEBUG_BUILD_FLAGS_FOR_CXX "-O0" )
elseif( MSVC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4 /WX")
endif()

include(build/sanitizers)
message(STATUS "")




