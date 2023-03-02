#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<iostream>
using namespace std;
int main(int argc, char *argument[])             //reciviing arguments at the command line
{
   int pid1 = fork();                   //staring with creating a child process
   if (pid1 == 0) {                     //condition for child process to execute
       cout<<"Child->1"<<endl;
       execlp("/bin/cat", "cat", argument[1], NULL);       //to run cat command
   }
   if(pid1>0)
   {
       wait(NULL);                //waitng for child
       int pid2 = fork();           //creating sceond child process
      
       if(pid2 == 0){
           cout<<"Child->2"<<endl;
           execlp("/usr/bin/wc", "wc", argument[1], NULL);       //to run wc command
       }
   }
else
cout<<"fork fail"<<endl;

   return 0;
}
