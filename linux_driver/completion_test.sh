#!/bin/bash

test_flag=$1
if [ 1 -eq $test_flag ]
then
    rmmod bz_completion_notify
    rmmod bz_module
    rmmod bz_add
    sleep 1
    echo insmod without time waiting.
    insmod bz_add.ko &
    sleep 1
    insmod bz_module.ko &
    sleep 3
    insmod bz_completion_notify.ko &
elif [ 0 -eq $test_flag ]
then
    rmmod bz_completion_notify
    rmmod bz_module
    rmmod bz_add
    sleep 1
    echo insmod with time waiting, 8s.
    insmod bz_add.ko &
    sleep 1
    insmod bz_module.ko &
    sleep 10
    insmod bz_completion_notify.ko &
else
    echo error input!
fi

dmesg -wH
