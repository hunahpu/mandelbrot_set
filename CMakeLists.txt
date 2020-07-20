cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
project("intiGL")
set(CMAKE_BUILD_TYPE Debug)
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(SOURCES "${SRC_DIR}/main.cpp" "${SRC_DIR}/VertexBuffer.cpp" "${SRC_DIR}/IndexBuffer.cpp"
    "${SRC_DIR}/VertexArray.cpp" "${SRC_DIR}/VertexBufferLayout.cpp"
    "${SRC_DIR}/Shader.cpp"  )
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libraries")
set(GLFW_DIR "${LIB_DIR}/glfw")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

set(RES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/res")
add_subdirectory("${GLFW_DIR}")
set(RESOURCE_FILES
  "${SRC_DIR}/default.shader"
)
file(COPY ${RES_DIR}/shaders/default.shader
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/res/shaders)



add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} "glfw" "${GLFW_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLFW_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${SRC_DIR}")
target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

set(GLAD_DIR "${LIB_DIR}/glad")
add_library("glad" "${GLAD_DIR}/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} "glad" "${CMAKE_DL_LIBS}")

