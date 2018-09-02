#include "ros/ros.h"
//#include "beginner_tutorials/AddTwoInts.h"
#include <cstdlib>

#include "ros_tutorials_param/SrvTutorial.h" // SrvTutorial서비스파일헤더 (빌드후자동생성됨)
#include <cstdlib>                            // atoll 함수사용을위한라이브러리


int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_client_param");
  if (argc != 3)
  {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }

  ros::NodeHandle nh;
  //ros::ServiceClient client = nh.serviceClient<beginner_tutorials::AddTwoInts>("ros_tutorial_srv");
  ros::ServiceClient ros_tutorials_service_client = nh.serviceClient<ros_tutorials_param::SrvTutorial>("ros_tutorial_srv");
  //beginner_tutorials::AddTwoInts srv;
  ros_tutorials_param::SrvTutorial srv;
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  if (ros_tutorials_service_client.call(srv))
  {
    //ROS_INFO("Sum: %ld", (long int)srv.response.sum);
    ROS_INFO("send srv, srv.Request.a and b: %ld, %ld", (long int)srv.request.a, (long int)srv.request.b);
    ROS_INFO("receive srv, srv.Response.result: %ld", (long int)srv.response.result);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}
