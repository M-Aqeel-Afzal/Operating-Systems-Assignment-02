#!/bin/sh


var1=">>$ "             #setting default shell variable


printf "%s " $var1                       
read -r input_command                     #taking input a commad from the user.


while [ "$input_commad" != "quit" ]      #loop will iterate untill user in 'quit'.
do
  
  $input_command                         #running the user command
 
 
  printf "%s " $var1
  read -r input_command                  #taking input a commad from the user.
done
