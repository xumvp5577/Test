#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>


int main(void)
{
	int fp;
	int n;
	char buf[]="Hello World\n";
	char buf1[1024]={0};
	fp=open("Hello",O_CREAT|O_RDWR,0777);
	if(fp<0)
	{
		perror("open Hello");
		exit(1);
	}
	printf("fp=%d\n",fp);
	write(fp,buf,strlen(buf));
	lseek(fp,0,SEEK_SET);
	n=read(fp,buf1,sizeof(buf1));
	printf("n=%d\n",n);
	if(n<0)	
	{
		perror("read Hello File :");
		exit(1);
	}
	write(STDOUT_FILENO,buf1,n);
	write(STDOUT_FILENO,"Hi\n",4);
	close(fp);

	return 0;
}
