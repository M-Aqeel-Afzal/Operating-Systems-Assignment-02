#include<iostream>
#include<unistd.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<sys/wait.h>
using namespace std;
int p_id[10];              //array to store ids for all nodes
int sum=0;
int main()                                 //creating Child A
{
p_id[0]=getpid();
 p_id[1]= vfork();                                 //creating Child Q
if(p_id[1]==0)
{
	p_id[2]= vfork();                                 //creating Child Z
        if(p_id[2]==0)
	{

	cout<<"Character: Z       no child                                   process ID "<<getpid()<<endl;
	sum=sum+'Z';
	exit(sum);



	}
	p_id[3]= vfork();                             //creating child  E
	
	if(p_id[3]==0&&p_id[2]>0)
	{
		p_id[4]= vfork();                             //creating child  A
		if(p_id[4]==0)
		{
				p_id[6]= vfork();                             //creating child  A
				if(p_id[6]==0)
				{

					cout<<"Character: A       no child                                   process ID "<<getpid()<<endl;
					sum=sum+'A';
					exit(sum);



				}

			cout<<"Character: A     "<<"       child1-id: "<<p_id[6]<<"                       process ID "<<getpid()<<endl;
			sum=sum+'A';
			exit(sum);



		}
		p_id[5]= vfork();                             //creating child  E
		if(p_id[5]==0&&p_id[4]>0)
		{
		p_id[7]= vfork();                             //creating child  L
			if(p_id[7]==0)

			{
				p_id[8]= vfork();                             //creating child  L
				if(p_id[8]==0)

				{
					cout<<"Character: L      no child                                    process ID "<<getpid()<<endl;
					sum=sum+'L';
					exit(sum);








				}
				p_id[9]= vfork();                             //creating child  F
				if(p_id[9]==0&&p_id[8]>0)

				{

					cout<<"Character: F       no child                                   process ID "<<getpid()<<endl;
					sum=sum+'F';
					exit(sum);







				}
				if(p_id[9]>0&&p_id[8]>0)
				{
				cout<<"Character: L       child1-id: "<<p_id[9]<<"        child2-id: "<<p_id[8]<<"     process ID "<<getpid()<<endl;
					sum=sum+'L';
					exit(sum);

                                }






			}
			if(p_id[7]>0)
			{
			cout<<"Character: E         child1-id: "<<p_id[7]<<"                          process ID "<<getpid()<<endl;
					sum=sum+'E';
					exit(sum);
			}
		}









	if(p_id[4]>0&&p_id[5]>0)
	{
	cout<<"Character: E     child1-id: "<<p_id[4]<<"    child2-id: "<<p_id[5]<<"           process ID "<<getpid()<<endl;
		sum=sum+'E';
		exit(sum);

	}

	}

	if(p_id[3]>0&&p_id[2]>0)
	{
	cout<<"Character: Q       child1-id: "<<p_id[2]<<"       child2-id: "<<p_id[3]<<"      process ID "<<getpid()<<endl;
	sum=sum+'Q';
	wait(NULL);
	exit(sum);
	}

}
if(p_id[1]>0)
{

cout<<"Character: A       child-id: "<<p_id[1]<<"                             process ID "<<p_id[0]<<endl;
sum=sum+'A';
cout<<"TOtal sum is: "<<sum<<endl;
wait(NULL);

}
else
cout<<"fail"<<endl;
	return 0;
}

