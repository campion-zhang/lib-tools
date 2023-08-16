#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

int main() {
    int fd;
    struct termios serial_settings;

    // 打开串口设备文件
    fd = open("/dev/pts/1", O_RDWR | O_NOCTTY);

    if (fd == -1) {
        perror("Error opening serial port");
        return 1;
    }

    // 配置串口参数
    memset(&serial_settings, 0, sizeof(serial_settings));
    serial_settings.c_cflag &= ~PARENB;   // 禁用校验位
    serial_settings.c_cflag &= ~CSTOPB;   // 使用一位停止位
    serial_settings.c_cflag &= ~CSIZE;    // 清除数据位设置
    serial_settings.c_cflag = B115200 | CS8 | CLOCAL | CREAD;
    tcsetattr(fd, TCSANOW, &serial_settings);

    // 发送数据
    char data[] = "Hello, RS-232!";
    ssize_t bytesWritten = write(fd, data, strlen(data));
    if (bytesWritten > 0) {
        printf("Data written successfully.\n");
    }

    // 接收数据
    while (1) {
    	char buffer[1024];
	int bytes_read = read(fd, buffer, sizeof(buffer));
	buffer[bytes_read] = '\0';
	if (bytes_read > 0) {
	    printf("Received data: %s\n", buffer);
	}
    }

    // 关闭串口设备文件
    close(fd);

    return 0;
}

