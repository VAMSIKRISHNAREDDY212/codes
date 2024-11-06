read -p "enter the number :" j
declare -i c=0
declare -i i=2
for ((i = 2; i < j; i++))
do
	if [ $((j % i)) -eq 0 ]
	then 
	       echo "not a prime"
               exit 0	       
	fi
done
	if [ $j -eq $i ]
	then
		echo "its a prime"
	fi

	          
