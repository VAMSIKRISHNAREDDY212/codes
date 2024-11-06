read -t 5 -p "enter the number :" p
while :
do
	echo -e " 1)quit \n  2)continue"
	read a
	if [ $a -eq 1 ]
	then
		exit 1
	else 
		read -t 5 -p "enter the number:" p
	fi
done
