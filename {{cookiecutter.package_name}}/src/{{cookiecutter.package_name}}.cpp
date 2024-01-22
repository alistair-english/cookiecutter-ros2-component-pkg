#include "{{cookiecutter.package_name}}/{{cookiecutter.package_name}}.hpp"

namespace {{cookiecutter.package_name}}
{

{{cookiecutter.__class_name}}::{{cookiecutter.__class_name}}(const rclcpp::NodeOptions& options) : Node("{{cookiecutter.package_name}}_node", options)
{
}

}  // namespace {{cookiecutter.package_name}}

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE({{cookiecutter.package_name}}::{{cookiecutter.__class_name}})