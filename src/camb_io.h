/** ==========================================
* @title: Camb_Io Node Class
* @class: This class is meant to be the interface with ros2 functionalities as such it derives node, Here you will find all the boilerplate for node common node behaviour.
* @author: João Vieira
* @date:   2023-07-24
========================================== **/

#ifndef CAMBIO_NODE_H_
#define CAMBIO_NODE_H_

#include <cstdio>
#include <string>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/node.hpp>
#include <rclcpp/executors.hpp>
#include <ackermann_msgs/msg/ackermann_drive.hpp>

#define LOWLEVELCONVERTER_NODE_NAME "LowLevelContextConverterNode"
#define ACKERMANN_TOPIC_NAME "ackermann_topic"
class CambIO : public rclcpp::Node{
	public:
		CambIO();
		virtual ~CambIO() = default;
		/**
		 * @brief Get the Node Name object
		 * 
		 * @return std::string
		*/
		std::string g_NodeName();
		/**
		 * @brief Getter for the topic name
		 * @return std::string 
		 **/
		std::string g_AckermannTopic();
	protected:
		void ackermann_callback(const ackermann_msgs::msg::AckermannDrive::SharedPtr msg);
		std::string m_ackermann_topic;
	private:
		rclcpp::Subscription<ackermann_msgs::msg::AckermannDrive>::SharedPtr m_ackermann_subscription;
};
#endif