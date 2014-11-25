#include "apue.h"
#include <sys/wait.h>

int main(void)
{
	pid_t pid ;
	if((pid = fork())<0){
		err_sys("fork error");
	}else if(pid == 0){			/* 第一个子进程 */ 
		if((pid = fork())<0){
			err_sys("fork error");
		}else if(pid > 0){
			exit(0);			/* 第二个子进程的父进程==第一个子进程*/
		}

		/*
		 * 这里是第二个子进程，由于第一个子进程已经退出了，
		 * 所以第二个子进程成为孤儿进程，由init进程收养，
		 * 第二个子进程终止后，由init进程回收，从而避免其成为僵尸
		 */

		sleep(10);
		printf("second child , parent pid = %ld\n",(long)getppid());
		exit(0);
	}

	if(waitpid(pid,NULL,0)!=pid)	/* 等待第一个子进程*/
		err_sys("waitpid error");

	exit(0);
}
