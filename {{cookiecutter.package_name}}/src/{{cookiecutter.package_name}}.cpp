#include "{{cookiecutter.package_name}}/{{cookiecutter.package_name}}.hpp"

namespace {{cookiecutter.package_name}}
{

{{cookiecutter.__class_name}}::{{cookiecutter.__class_name}}(const rclcpp::NodeOptions& options) : Node("{{cookiecutter.package_name}}_node", options)
{
    param_listener_ = std::make_shared<ParamListener>(get_node_parameters_interface());
    params_ = param_listener_->get_params();
}

}  // namespace {{cookiecutter.package_name}}

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE({{cookiecutter.package_name}}::{{cookiecutter.__class_name}})