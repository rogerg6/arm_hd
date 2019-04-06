#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <poll.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int fd;

/* sixth drive */
void my_signal_func(int signum)
{
	unsigned char key_val;
	read(fd, &key_val, 1);
	printf("key_val: 0x%x\n", key_val);
}

int main(int argc, char ** argv)
{
	unsigned char key_val;
	int ret;
	int Oflags;

	//signal(SIGIO, my_signal_func);	/* 将信号定位到my_signal_func */

	fd = open("/dev/buttons", O_RDWR | O_NONBLOCK);  /* 非阻塞 */
	if (fd < 0)
	{
		printf("can't open!\n");
		return -1;
	}

	//fcntl(fd, F_SETOWN, getpid());	/* 获取进程ID，告诉驱动信号接收者 */
	
	//Oflags = fcntl(fd, F_GETFL);    /* 改变fasync标记 */

	/* 调用到驱动的faync > fasync_helper：
	 * 初始化/释放fasync_struct 
	 */
	//fcntl(fd, F_SETFL, Oflags | FASYNC);	

	while (1)
	{
		ret = read(fd, &key_val, 1);
		printf("key_val: 0x%x, ret = %d\n", key_val, ret);
		sleep(5);
	}
	
	return 0;
}
