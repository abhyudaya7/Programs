#!/usr/bin/env python3
import shutil
import psutil

def check_free_disk_space(disk) :
    du = shutil.disk_usage(disk) 
    free_space = du.free / du.total * 100
    return free_space > 20

def check_cpu_usage() :
    usage = psutil.cpu_percent(1)
    return usage < 75


if not check_free_disk_space('/') and not check_cpu_usage():
    print("System needs attention") 
else :
    print ("Everything is fine")

