#########################################################################
# File Name: myshell.sh
# Author: lys
# mail: liyishengchn@gmail.com
# Created Time: Sat 24 Jan 2015 04:38:30 PM PST
#########################################################################
#!/bin/bash
if [ -f /bin/bash]
then
	echo "file /bin/bash exits"
fi

if [ -d /bin/bash ]
then
	echo "/bin/bash is a directory"
else
	echo "bin/bash is NOT a directory"
fi
