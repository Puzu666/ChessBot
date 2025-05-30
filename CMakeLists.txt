cmake_minimum_required(VERSION 3.25)

project(ChessBot LANGUAGES CXX)

set(SOURCE_DIR source)
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")

add_executable("${PROJECT_NAME}" ${SOURCES})

target_include_directories("${PROJECT_NAME}" PRIVATE "${PROJECT_SOURCE_DIR}/include")

# Définir les options du compilateur
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=undefined -fsanitize=address -fno-omit-frame-pointer)
target_link_options   (${PROJECT_NAME} PRIVATE -fsanitize=undefined -fsanitize=address -fno-omit-frame-pointer)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -pedantic-errors -Wno-unknown-pragmas)
    if(ANALYSE_STATIQUE)
        target_compile_options(${PROJECT_NAME} PRIVATE -fanalyzer)
    endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()