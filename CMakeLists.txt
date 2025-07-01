cmake_minimum_required(VERSION 3.20) 
project(tiny_rpg C)

set(CMAKE_C_STANDARD 99)

# Set default build type if not specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the build type." FORCE)
endif()

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.c")

# Detect platform
if(WIN32)
    if(MSVC)
        message(STATUS "Configuring MSVC flags on Windows")

        # Debug flags
        set(CMAKE_C_FLAGS_DEBUG "/W4 /Od /Zi /MP /RTC1")

        # Release flags
        set(CMAKE_C_FLAGS_RELEASE "/O2 /GL /fp:fast /W3 /DNDEBUG")
        set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/LTCG /INCREMENTAL:NO /SUBSYSTEM:CONSOLE")

    else()
        message(FATAL_ERROR "Unsupported compiler on Windows! (Expecting MSVC)")
    endif()

    # You can adjust this path if needed
    set(RAYLIB_DIR "C:/ExternalLibs/raylib-5.5_win64_msvc16")
    include_directories("${RAYLIB_DIR}/include")
    link_directories("${RAYLIB_DIR}/lib")

    # Windows-specific libraries
    set(EXTRA_LIBS
        raylib
        opengl32
        gdi32
        winmm
        user32
        kernel32
        shell32
        comdlg32
        uuid
    )

elseif(APPLE)
    message(STATUS "Configuring for macOS")

    include_directories("/opt/homebrew/include")
    link_directories("/opt/homebrew/lib")

    # macOS-specific libraries
    set(EXTRA_LIBS
        raylib
        m
        dl
        pthread
        "-framework OpenGL"
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
    )

else()
    message(FATAL_ERROR "Unsupported platform")
endif()

# Add executable
add_executable(tiny_rpg ${SOURCES})

if (MSVC)
    # Silences deprecation warnings from MSVC
    message(STATUS "Set _CRT_SECURE_NO_WARNINGS to ON for MSVC.")
    target_compile_definitions(tiny_rpg PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

# Link libraries
target_link_libraries(tiny_rpg PRIVATE ${EXTRA_LIBS})
