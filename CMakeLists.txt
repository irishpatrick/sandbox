cmake_minimum_required(VERSION 3.0)

set(PKG_MANAGER "vcpkg" CACHE STRING "desc")

project(sandbox C CXX)

if (MSVC)
    message(STATUS "Platform: MSVC")
    set(LIBS opengl32)
endif()

if (${PKG_MANAGER} STREQUAL "pkg-config")

find_package(PkgConfig REQUIRED)

pkg_check_modules(box2d REQUIRED box2d)
pkg_check_modules(glfw3 REQUIRED glfw3)
pkg_check_modules(glew REQUIRED glew)
pkg_check_modules(glfw3 CONFIG REQUIRED)

set(
    LIBS 
    ${LIBS}
    ${glew_LIBRARIES} 
    ${glfw3_LIBRARIES} 
    ${box2d_LIBRARIES} 
    stdc++fs
)

endif ()

if (${PKG_MANAGER} STREQUAL "vcpkg")

find_package(unofficial-box2d CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

set(
    LIBS
    ${LIBS}
    GLEW::GLEW
    glfw
    unofficial::box2d::Box2D
)


endif ()

file(GLOB sources src/*.cpp)
file(GLOB headers src/*.hpp src/*.inl)
file(GLOB assets assets/*)

add_executable(${PROJECT_NAME} ${sources} ${headers})

target_link_libraries(
    ${PROJECT_NAME} 
    PRIVATE 
    ${LIBS}
)

file(COPY ${assets} DESTINATION ./assets)
