read -p "enter the threshold value :" p
a=`ls -d */|wc -l`
echo "the no of directories : $a"
b=`ls |wc -l`
echo $b
b=$((b - a))
echo "the no of files: $b"
if [ $b -gt $p ]
then 
     echo "warning :reaches the threshold level:"
else
	echo "with in the threshold level"
fi
