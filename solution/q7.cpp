#include<iostream>
#include<unistd.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<sys/wait.h>
using namespace std;
int main()
{
	string str;
	int c1,c2,c3,c4,c5,c6,signal;
	cout<<"Enter the string: ";
	cin>>str;
	c1=fork();            //first child creation
	if(c1>1)
	{
			cout<<"\nparent: ";
			cout<<"original string: "<<str<<endl;
			cout<<endl;
	}

		else if(c1==0)
		{
			wait(NULL);
			cout<<"child->1: ";
			cout<<"Reversing of the string: ";
			int temp,i=0;
			char c;
			temp=str.length();
			
			while(i<temp/2)
			{
				c=str[i];
				str[i]=str[temp-1-i];
				str[temp-1-i]=c;
				i++;
			}
			cout<<str<<endl;
			cout<<endl;
			c2=fork();                                                           //second child creation

			if(c2==0)
			{
				wait(NULL);
				cout<<"child->2: ";
				cout<<"finding length of the string: "<<str.length()<<endl<<endl;
				c3=fork();                                                   //third child creation

				if(c3==0)
				{
					wait(NULL);
					cout<<"child->3: ";
					cout<<"addition of 2 in each character of the string: ";
					int i=0,len;
					
					len=str.length();
					while(i<len)
					{
						str[i]=str[i]+2;
						i++;
					}
					cout<<str<<endl;
					cout<<"\n";
					c4=fork();                                  //fourth child creation

					if(c4==0)
					{
						wait(NULL);
						cout<<"child->4: ";
						cout<<"sorting of the string: ";
						sort(str.begin(), str.end());
						cout<<str<<endl;
						cout<<endl;
						c5=fork();                                  //fifth child creation

						if(c5==0)
						{

							wait(NULL);
							cout<<"child->5: ";
							cout<<"string in capital: ";
							int i=0,len;
							len=str.length();
							while(i<len)
							{
								if(str[i]>96)
								{
									str[i]=str[i]-32;
								}
								i++;
							}
							cout<<str<<endl;	
							cout<<endl;

						}
					}
				}
			}
		}
	return 0;
}
