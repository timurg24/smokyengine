set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


cmake_minimum_required(VERSION 3.22)

project(SmokyEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Executables
add_executable(SmokyEngine
    src/main.cpp
    src/global.cpp
    src/pugixml.cpp

    src/Scene/Scene.cpp

    src/Entity/Entity.cpp
)

# Linking libraries
target_include_directories(SmokyEngine PRIVATE src)
target_include_directories(SmokyEngine PRIVATE ${CMAKE_SOURCE_DIR}/external/include)

if(UNIX AND NOT MINGW)
    target_link_directories(SmokyEngine PRIVATE ${CMAKE_SOURCE_DIR}/external/lib/gcc)
    target_link_libraries(SmokyEngine PRIVATE
        raylib
        liblua
        m pthread dl rt X11
    )
elseif(MINGW)
    target_link_directories(SmokyEngine PRIVATE ${CMAKE_SOURCE_DIR}/external/lib/mingw)
    target_link_libraries(SmokyEngine PRIVATE
        raylib
        winmm
        lua54
    )
elseif(MSVC)
    target_link_directories(SmokyEngine PRIVATE ${CMAKE_SOURCE_DIR}/external/lib/msvc)
    target_link_libraries(SmokyEngine PRIVATE
        raylib
    )
endif()