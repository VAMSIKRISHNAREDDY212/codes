declare -i a=1
read -p "enter the number:" d
for ((i = $d; i >= 1; i--))
do
	a=$((a * i))
done
echo $a
	

