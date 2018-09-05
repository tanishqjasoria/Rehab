#!/bin/bash
import sleep
STRING="Hello World"
#STRING2="Hello World2"

pi1()
{
        sshpass -p 'raspberry' ssh pi@192.168.43.157 /bin/bash <<EOF
                cd /home/pi/Rehab_proj/
                echo Start129
		python Serial_test.py
EOF
}

pi2()
{
        sshpass -p 'krssg17' ssh pi@192.168.43.227 /bin/bash <<EOF
                cd /home/pi/Desktop/Rehab227/
                echo Start
                python Serial_test227.py
EOF
}

pi3()
{
        sshpass -p 'raspberry' ssh pi@192.168.43.34 /bin/bash <<EOF
                cd /home/pi/Desktop/Rehab
		echo Start
                python Serial_test1.py
EOF
}

export -f pi1
export -f pi2
export -f pi3


gnome-terminal --window-with-profile=Rehabi -e "bash -c 'pi1'" &

gnome-terminal --window-with-profile=Rehabi -e "bash -c 'pi2'" &

gnome-terminal --window-with-profile=Rehabi -e "bash -c 'pi3'"
