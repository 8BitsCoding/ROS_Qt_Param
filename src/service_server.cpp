#include "ros/ros.h"
//#include "beginner_tutorials/AddTwoInts.h"

#include "ros_tutorials_param/SrvTutorial.h"

#define PLUS              1
#define MINUS             2
#define MULTIPLICATION    3
#define DIVISION          4

int g_operator = PLUS;

bool calculation(ros_tutorials_param::SrvTutorial::Request &req, ros_tutorials_param::SrvTutorial::Response &res)
{
switch(g_operator)
{
case PLUS:
  res.result = req.a + req.b;
  break;
case MINUS:
  res.result = req.a - req.b;
  break;
case MULTIPLICATION:
  res.result = req.a * req.b;
  break;
case DIVISION:
  if(req.b == 0)
  {
    res.result = 0;
    break;
  }
  else
  {
    res.result = req.a / req.b;
    break;
  }
default:
  res.result = req.a + req.b;
  break;
}

// 서비스요청에사용된 a, b 값의표시및서비스응답에해당되는result 값을출력한다 ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
ROS_INFO("sending back response: %ld", (long int)res.result);

return true;
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_server_param");
  ros::NodeHandle nh;

  nh.setParam("calculation_method", PLUS);

  ros::ServiceServer service = nh.advertiseService("ros_tutorial_srv", calculation);
  ROS_INFO("Ready srv server!");

  ros::Rate r(10);

  while(1)
  {
    nh.getParam("calculation_method", g_operator);
    ros::spinOnce();
    r.sleep();
  }


  return 0;
}
