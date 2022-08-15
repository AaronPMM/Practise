#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <err.h>

static void child()
{
    printf("I'm child! my pid is %d.\n", getpid());
    exit(EXIT_SUCCESS); 
}


void parent(pid_t pid) 
{

    printf("PARENT <%ld> Spawned a child with PID = %ld.\n",
           (long) getpid(), (long) pid);

    printf("PARENT <%ld> Press any key to reap a zombie!\n",
           (long) getpid());

    getchar();

    pid = wait(NULL);

    printf("PARENT <%ld> Zombie child with PID = %ld",
           (long) getpid(), (long) pid);

    exit(EXIT_SUCCESS);
}


int main(void)
{
    pid_t ret;
    ret = fork();
    if(ret == -1)
    {
        err(EXIT_FAILURE, "fork() faild");
    }

    if(ret == 0)
    {
        //child
        child();
    }
    else
    {
        parent(ret);
    }
    
    err(EXIT_FAILURE, "shoudn't reach here");
}
