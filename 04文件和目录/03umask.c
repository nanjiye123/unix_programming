//创建两个文件，创建第一个时，umask值为0,
//创建第二个时，umask值禁止所有组和其他用户的访问权限
#include <apue.h>
#include <fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(void)
{
	umask(0);
	if(creat("foo", RWRWRW) < 0)
	{
		err_sys("creat error for foo");	
	}

	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);	
	if(creat("bar", RWRWRW) < 0)
	{
		err_sys("creat error for bar");	
	}
	exit(0);
}

