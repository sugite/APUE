#include<fcntl.h>
#include "apue.h"

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
	int fd ; 
	if((fd=open("file.hole",O_CREAT|O_RDWR|O_TRUNC,FILE_MODE))==-1)
		err_sys("creat error");

	if(write(fd,buf1,10)!=10)
		err_sys("write error");
	/* offset now = 10 */
	
	if(lseek(fd,16384,SEEK_SET)==-1)
		err_sys("lseek error");
	/* offset now = 16384*/

	if(write(fd,buf2,10)!=10)
		err_sys("buf2 write error");
	/* offset now = 16394*/

	return 0;
}
