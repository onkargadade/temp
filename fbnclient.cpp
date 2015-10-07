#include"ros/ros.h"
#include <assignments/fib.h>
#include <cstdlib>
//#include "std_msgs/Int64.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "fbnclient");
	if(argc != 2)
	{ 
	ROS_INFO("argc pain");
	return 1;
	}
	
	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient <assignments::fib>("fib");
	
	assignments::fib srv;
	srv.request.a = atoll(argv[1]);
	if (client.call(srv))
	{
	 ROS_INFO("fbn = %ld", (long int) srv.response.fbn);
	}
	else
	{
		ROS_ERROR("failed to call service");
		return 1;
	}
	return 0;
}
