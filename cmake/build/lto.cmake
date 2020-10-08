cmake_minimum_required(VERSION 3.9)
if (NOT (CMAKE_CXX_PLATFORM_ID MATCHES "MinGW"))

    # Enable Link-Time Optimization, AKA Inter-Procedure Optimization
    if (NOT ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug"))
        include(CheckIPOSupported)
        check_ipo_supported(RESULT LTOAvailable OUTPUT output)
    endif ()

    if (LTOAvailable)
        message(STATUS "LINK-TIME OPTIMIZATION: \t ON")
        set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
    else()
        message(STATUS "LINK-TIME OPTIMIZATION: \t\t OFF" )
    endif ()

endif ()
