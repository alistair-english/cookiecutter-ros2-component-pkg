cmake_minimum_required(VERSION 3.12)
project({{cookiecutter.package_name}})

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

generate_parameter_library(${PROJECT_NAME}_parameters src/parameters.yaml)

ament_auto_add_library(${PROJECT_NAME}_node_component SHARED src/{{cookiecutter.package_name}}.cpp)

target_link_libraries(${PROJECT_NAME}_node_component ${PROJECT_NAME}_parameters)

target_compile_definitions(${PROJECT_NAME}_node_component PRIVATE "{{cookiecutter.__package_name_upper}}_BUILDING_LIBRARY")

rclcpp_components_register_node(${PROJECT_NAME}_node_component
  PLUGIN "{{cookiecutter.package_name}}::{{cookiecutter.__class_name}}"
  EXECUTABLE ${PROJECT_NAME}_node
)

ament_auto_package(
  INSTALL_TO_SHARE
  launch
)