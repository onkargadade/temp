#include "ros/ros.h"
#include "assignments/fib.h"
//#include "std_msgs/Int64.h"
int fbnfn(long int n)
{       
	if(n==1 ||n==2)return 1;
	else
	{
		return fbnfn(n-1)+fbnfn(n-2);
	}

}
bool vfbn(assignments::fib::Request &req,
		assignments::fib::Response &res )
{
	res.fbn = fbnfn(req.a);
	ROS_INFO("request : number= %ld", (long int) req.a);
	ROS_INFO("fbn number = %ld", (long int) res.fbn );
	return true;

}

int main(int argc, char **argv)
{	
	ros::init(argc, argv, "fbn");
	ros::NodeHandle n;

	ros::ServiceServer client = n.advertiseService("fib", vfbn);
	ROS_INFO("printing fbn- ");
	ros::spin();

	return 0;
}
