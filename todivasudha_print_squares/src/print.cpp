#include "ros/ros.h"
#include "std_msgs/Int16.h"

/*
  This node will subscribe to both topic_numbers and topic_squares and output them using ROS_INFO. The output will indicate the name of the 
  topic that the output has come from. 
 */

/*
 the following callback functions print the messages suscribed from the topics respectively.
*/

void topic_numbersCallback(std_msgs::Int16 msg) 
{
  ROS_INFO("topic_numbers: [%d]", msg.data);
}

void topic_squaresCallback(std_msgs::Int16 msg)
{
  ROS_INFO("topic_squares: [%d]", msg.data);
}


int main(int argc, char **argv)
{
  /*
    the ros::init() function is called before using any part of the ros system. the third argument here is the name of the node.
   */
  ros::init(argc, argv, "print");

  /*
    NodeHandle is the main access point to communications with the ROS system.
    The first NodeHandle constructed will fully initialize this node, and the last
    NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;

  /*
   the susucribe() function tells ros that we want to receive messages on the given topic.
   messages are passed to a callback function.
 */
  ros::Subscriber sub1 = n.subscribe("topic_numbers", 1000, topic_numbersCallback);
  ros::Subscriber sub2 = n.subscribe("topic_squares", 1000, topic_squaresCallback);

  /*
    ros::spin() will enter a loop, pumping callbacks.
    all callbacks will be called from within this thread. 
    ros::spin() will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */
  ros::spin();

  return 0;
}
