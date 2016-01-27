#include <apue.h>
#include <fcntl.h>

void set_fl(int fd, int flags)
{//对一个文件描述符开启一个或多个文件状态标志
	int val;
	if( (val = fcntl(fd, F_GETFL, 0)) < 0 )
	{//返回fd的文件状态标志
		err_sys("fcntl F_GETFL error");	
	}
	val |= flags;//开启标志
	//val &= ~flags;//关闭标志
	if( fcntl(fd, F_SETFL, val) < 0 )
	{//设置fd的文件状态标志
		err_sys("fcntl F_SETFL error");	
	}
	
}


int main()
{
	set_fl(STDOUT_FILENO, O_SYNC);
	//开启了同步写标志，使每次write都要等待，直到数据已写到磁盘上再返回

	exit(0);
}



