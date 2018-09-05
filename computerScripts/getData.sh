echo  "Enter Name :"
read varname
echo $varname
mkdir ~/$varname
sshpass -p 'raspberry' scp pi@192.168.43.34:/home/pi/Desktop/Rehab/test_data.txt /home/abhishek/$varname/test_data34.txt
sshpass -p 'raspberry' scp pi@192.168.43.157:/home/pi/Rehab_proj/test_data.txt /home/abhishek/$varname/test_data129.txt
sshpass -p 'krssg17' scp pi@192.168.43.227:/home/pi/Desktop/Rehab227/test_data.txt  /home/abhishek/$varname/test_databack.txt

