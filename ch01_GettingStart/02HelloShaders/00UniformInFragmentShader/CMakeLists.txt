project(uniforminfragmentshader)

find_package(glfw3 CONFIG REQUIRED)

find_package(glad CONFIG REQUIRED)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
  PRIVATE main.cc
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE glfw
  PRIVATE glad::glad
)