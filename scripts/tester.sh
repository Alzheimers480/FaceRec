#set -x
for f in *.pgm; do
    x=$(realpath $f)
    y=$(~/cv-dev/faces predict "$x" | awk -F: '{print $2}')
    z=$(basename $(pwd) | awk '{gsub ("^s0*", "", $0); print}')
    if [ "$y" -ne "$z" ]
    then
	echo "false"
    else
	echo "true"
    fi
done;
