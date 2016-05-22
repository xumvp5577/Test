#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char buf[1024]={0};
	int n;
	printf("%d\n",STDIN_FILENO);
	n=read(STDIN_FILENO,buf,1024);
	if(n<0)
	{
		perror("read STDIN_FILENO");
		exit(1);
	}
	write(STDIN_FILENO,buf,n);
	return 0;



}
