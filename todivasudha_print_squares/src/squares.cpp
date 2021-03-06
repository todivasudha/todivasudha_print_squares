#include "ros/ros.h"
#include "std_msgs/Int16.h"

/*
  This node will subscribe to topic_numbers and publish the squares of the numbers to another topic, topic_squares.
 */
void topic_numbersCallback(std_msgs::Int16 msg)
{
  ros::NodeHandle n;
 /*
   the advertise() function tells ros that we want to publish on a given topic.
   */
  ros::Publisher pub = n.advertise<std_msgs::Int16>("topic_squares", 1000);

  msg.data=msg.data*msg.data;
  pub.publish(msg);
}

int main(int argc, char **argv)
{
  /*
    the ros::init() function is called before using any part of the ros system. the third argument here is the name of the node.
   */
  ros::init(argc, argv, "squares");

  /*
    NodeHandle is the main access point to communications with the ROS system.
    The first NodeHandle constructed will fully initialize this node, and the last
    NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;

   /*
   the susucribe() function tells ros that we want to receive messages on the given topic.
   messages are passed to a callback function (here topic_numbersCallback).
 */
  ros::Subscriber sub = n.subscribe("topic_numbers", 1000, topic_numbersCallback);

  /*
    ros::spin() will enter a loop, pumping callbacks.
    topic_numberCallback() will be called from within this thread. 
    ros::spin() will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */
  ros::spin();

  return 0;
}
