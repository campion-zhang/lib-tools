#!/bin/bash

counter=1
max_iterations=100   # 设定最大累加次数

while [ $counter -le $max_iterations ]
do
    echo "serial port test $counter" > /dev/pts/5
    # 在这里替换为你要执行的命令
    ((counter++))   # 累加计数器
    sleep 1   # 可以添加延时，避免过快执行
done

