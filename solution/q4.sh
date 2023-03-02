#!/bin/sh
#MUHAMMAD AQEEL AFZAL
#i190650
#Section-D
printf "                                   List of Dirctories and Files\n\n\n" >>temp1.txt
 ls >> temp1.txt                                                                          #showing list

printf "\n\n\n                             Searching the string\n\n\n" >>temp1.txt
find . -name '*' -exec  grep  -r  'i190650' {} \; >> temp1.txt                               #searching for required string
printf "\n\n\n                             Setting path of Home to 'PATH' variable \n\n\n" >>temp1.txt
export PATH="$HOME/bin:$PATH"                               #setting path
printf $Path >>temp1.txt











