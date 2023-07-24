#include "camb_io.h"
#include <ackermann_msgs/msg/detail/ackermann_drive__struct.hpp>
		
CambIO::CambIO() : Node(LOWLEVELCONVERTER_NODE_NAME){
	this->declare_parameter(ACKERMANN_TOPIC_NAME, "/");
	this->get_parameter(ACKERMANN_TOPIC_NAME, m_ackermann_topic);

	m_ackermann_subscription = this->create_subscription<ackermann_msgs::msg::AckermannDrive>(m_ackermann_topic, 10,std::bind(&CambIO::ackermann_callback, this, std::placeholders::_1));
		
}
void CambIO::ackermann_callback(const ackermann_msgs::msg::AckermannDrive::SharedPtr msg){
	RCLCPP_INFO(this->get_logger(), "I heard: [%f]", msg->speed);
}dada
std::string CambIO::g_NodeName(){
	return LOWLEVELCONVERTER_NODE_NAME;
}
		
std::string CambIO::g_AckermannTopic(){
	return m_ackermann_topic;
}
