cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(template VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*)
set(EXTERNAL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external)
add_executable(${PROJECT_NAME} ${SRC_FILES})

# definitions for ressource paths and prg info
add_compile_definitions(SHADER_PATH="${CMAKE_CURRENT_SOURCE_DIR}/shaders/")
add_compile_definitions(PRG_NAME="${PROJECT_NAME}")
add_compile_definitions(PRG_VERSION="${CMAKE_PROJECT_VERSION}")

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${EXTERNAL_DIR})

# build glfw
add_subdirectory(${EXTERNAL_DIR}/glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

# build glm
add_subdirectory(${EXTERNAL_DIR}/glm)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)

add_subdirectory(${EXTERNAL_DIR}/glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)
