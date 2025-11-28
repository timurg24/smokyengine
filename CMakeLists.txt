set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


cmake_minimum_required(VERSION 3.22)

project(SmokyEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(EXTERNAL_DIR         "${CMAKE_SOURCE_DIR}/external")
set(EXTERNAL_INCLUDE_DIR "${EXTERNAL_DIR}/include")
set(EXTERNAL_LIB_DIR     "${EXTERNAL_DIR}/lib/linux")

add_library(raylib STATIC IMPORTED)

set_target_properties(raylib PROPERTIES
    IMPORTED_LOCATION             "${EXTERNAL_LIB_DIR}/libraylib.a"
    INTERFACE_INCLUDE_DIRECTORIES "${EXTERNAL_INCLUDE_DIR}"
)

set(RAYLIB_SYSTEM_LIBS
    m
    pthread
    dl
    rt
    X11
)

add_executable(SmokyEngine
    src/main.cpp
    src/pugixml.cpp

    src/Entity/Entity.cpp

    src/Scene/Scene.cpp
    
)


target_include_directories(SmokyEngine PRIVATE "${EXTERNAL_INCLUDE_DIR}")
target_include_directories(SmokyEngine PRIVATE src)

target_link_libraries(SmokyEngine PRIVATE
    raylib
    ${RAYLIB_SYSTEM_LIBS}
)
