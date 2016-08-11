#!/bin/bash

while true ; do
    insmod kern_syms.ko
    rmmod kern_syms
    sleep 1
done
