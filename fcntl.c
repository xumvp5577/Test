# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>


# define MSG_TRY "Try again\n"


int main (void)
{
	int n=0,flags=0;
	char buf[1024]={0};
	flags=fcntl(STDIN_FILENO,F_GETFL);
	flags|=O_NONBLOCK;
	if(fcntl(STDIN_FILENO,F_SETFL,flags)==-1)
	{
		perror("fcntl:");
		exit(1);
	}
tryagain:
	n=read(STDIN_FILENO,buf,sizeof(buf));
	printf("n=%d\n",n);
	if(n<0)
	{
		if(errno==EAGAIN)
		{
			sleep(2);
			write(STDOUT_FILENO,MSG_TRY,sizeof(MSG_TRY));
			goto tryagain;
		}
		perror("read error:");
		exit(1);
	}
	write(STDOUT_FILENO,buf,strlen(buf));
	printf("strlen(buf)=%d\n",strlen(buf));
	return 0;
}

