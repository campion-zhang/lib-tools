1、开启虚拟串口

sudo socat -d -d pty,raw,echo=0 pty,raw,echo=0

输出：
2023/08/15 17:23:33 socat[28131] N PTY is /dev/pts/1
2023/08/15 17:23:33 socat[28131] N PTY is /dev/pts/5
表示串口1和串口5可以相互通信
2、接收串口
cat /dev/pts/5

3、发送串口
echo "serial port test" > /dev/pts/1
