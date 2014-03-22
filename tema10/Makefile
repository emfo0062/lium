test:
	echo "**** Testing timetrack (f) ****"
	./timetrack.sh status
	./timetrack.sh start
	sleep 1
	./timetrack.sh status
	sleep 1
	./timetrack.sh stop
	./timetrack.sh status
	./timetrack.sh start
	sleep 1
	./timetrack.sh stop

	echo "**** Testing checkuser (g) ****"
	echo "Testing with `whoami`"
	./checkuser.sh `whoami`
	if [[ $? -eq 0 ]];then echo "[OK]";else echo "[FAIL]";fi
	echo "Testing with xxx`whoami`"
	./checkuser.sh xxx`whoami`
	if [[ $? -eq 0 ]];then echo "[OK]";else echo "[OK]";fi

	echo "**** Testing print2lines.py (h) *****"
	./print2lines.py