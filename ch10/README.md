#信号#

##信号概念##

每个信号都有一个名字，都以3个字符SIG开头，如：    
* SIGABRT是夭折信号，当进程调用abort函数时产生这种信号   
* SIGALRM是闹钟信号，有alarm函数设置的定时器超时后会产生此信号   

在头文件`<signal.h>`中，信号名都被定义为正整数常量。   
不存在编号为0的信号，即空信号。   

信号的处理：   
1. 忽略此信号，SIGKILL和SIGSTOP两种信号不能被忽略   
2. 捕捉信号，上面两个信号不能被捕捉   
3. 执行系统默认操作，对大多数信号的系统默认动作是终止该进程   

##函数signal##

```C
#include<signal.h>
void (*signal(int signo , void (*func)(int)))(int);
//若成功，返回以前的信号处理配置，否则返回SIG_ERR
```
signo是信号名,func的值是SIG_IGN(表示忽略)、SIG_DFL(系统默认动作)或函数地址。

上面的函数原型比较复杂，可以如下简化：
```C
typedef void Sigfunc(int);
Sigfunc *signal(int , Sigfunc *);
```
而SIG_IGN和SIG_DFL等则声明如下：
```C
#define SIG_ERR (void (*)())-1
#define SIG_DFL (void (*)())0
#define SIG_IGN (void (*)())1
```

**当进程第一次执行时，所有的信号都被设为默认操作，除非父进程忽略它们**


