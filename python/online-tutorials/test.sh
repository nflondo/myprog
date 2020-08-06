#!/bin/bash
echo "---START - This is the script test running --- START"
echo "Print the alphabet in one line"
for i in {a..z}
do
       echo -n "$i" >> /tmp/test.log
done
echo -e "\n-------End of script----------"       
