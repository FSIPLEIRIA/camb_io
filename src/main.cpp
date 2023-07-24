#include <cstdio>
#include <memory>
#include <rclcpp/executors.hpp>
#include <rclcpp/node.hpp>
#include <rclcpp/rclcpp.hpp>
#include "camb_io.h"
int main(int argc, char ** argv){
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<CambIO>());
	
	rclcpp::shutdown();

	return 0;
}