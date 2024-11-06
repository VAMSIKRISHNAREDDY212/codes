declare -i b=0
for f in $(cat client.c)
do
   echo ${f[0]}
done

