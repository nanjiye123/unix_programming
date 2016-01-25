//用于测试对其标准输入能否设置偏移量
#include <apue.h>

int main()
{
	if( lseek(STDIN_FILENO, 0, SEEK_CUR) == -1 )
	{
		printf("cannot seek\n");
	}
	else
	{
		printf("seek ok\n");		
	}
	exit(0);
}
