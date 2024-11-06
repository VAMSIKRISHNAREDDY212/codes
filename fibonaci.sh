declare -i a=0
declare -i b=1
declare -i i=0
echo $a
echo $b
for ((i = 0; i < 20; i++)) 
do
	c=$((a + b))
	a=$b
	b=$c
	echo $c
done
	

