cmake_minimum_required(VERSION 3.19.7)

include_directories("${GLFW_SOURCE_DIR}/deps")

project(opengl_2dscene)

set(GLAD_GL "${GLFW_SOURCE_DIR}/deps/glad/gl.h"
            "${GLFW_SOURCE_DIR}/deps/glad_gl.c"
)

add_executable(${PROJECT_NAME} triangle-opengl.c ${GLAD_GL})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE external/glfw/src
)

target_link_libraries(${PROJECT_NAME} glfw)