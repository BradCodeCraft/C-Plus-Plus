cmake_minimum_required(VERSION 3.31.5)

project(Library)

add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(lib/Book)

target_link_libraries(${PROJECT_NAME} book)
