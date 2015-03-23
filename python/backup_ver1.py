#########################################################################
# File Name: backup_ver1.py
# Author: liyisheng
# mail: liyishengchn@gmail.com
# Created Time: Sat 14 Mar 2015 08:13:31 PM CST
#########################################################################
#!/bin/python

import os
import time

source = ['/home', '/home']

target_dir = '/mnt/e/backup/'

target = target_dir + time.strftime('%Y%m%d%H%M%S') + '.zip'

zip_command = "zip -qr '%s' %s" % (target, ' '.join(source))

if os.system(zip_command) == 0:
	print 'Successful backup to', target
else:
	print 'Backup Failed'
