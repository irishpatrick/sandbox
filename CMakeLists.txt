cmake_minimum_required(VERSION 3.0)

project(sandbox C CXX)

find_package(PkgConfig REQUIRED)

pkg_check_modules(box2d REQUIRED box2d)
pkg_check_modules(glfw3 REQUIRED glfw3)
pkg_check_modules(glew REQUIRED glew)

file(GLOB sources src/*.cpp)
file(GLOB headers src/*.hpp src/*.inl)
file(GLOB assets assets/*)

add_executable(${PROJECT_NAME} ${sources} ${headers})

target_link_libraries(
    ${PROJECT_NAME} 
    PRIVATE 
    ${box2d_LIBRARIES} 
    ${glew_LIBRARIES} 
    ${glfw3_LIBRARIES} 
    stdc++fs
)

file(COPY ${assets} DESTINATION ./assets)
