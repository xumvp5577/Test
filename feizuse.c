# include <unistd.h> 
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>

#define MSG_TRY "Try again\n"

int main(void)
{
	char buf[1024];
	int fd,n;
	// 当前终端 /dev/tty
	fd=open("/dev/tty",O_RDONLY|O_NONBLOCK);
	if(fd<0)
	{ 
		perror("open /dev/tty:");
		exit(1);
	}
tryagain:
	n=read(fd,buf,sizeof(buf));
	if(n<0)
	{
		if(errno==EAGAIN)
		{
			sleep(1); 
			write(STDOUT_FILENO,MSG_TRY,strlen(MSG_TRY));	; 
			goto tryagain; 
		}
		perror("read /dev/tty:");
		exit(1);
	}	
	write(STDOUT_FILENO,buf,n);
	close(fd);
 	return 0;
}
