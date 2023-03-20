#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "memwatch.h"

static void usr_signo(int signo)
{
    if(signo == SIGUSR2);
    {
        printf("reviced SIGUS2\n");
        mwTerm(); 
        exit(0);
    }
}

int main(void)
{
    #ifdef DEBUG_HONG
    printf("open hong dingyi");
    #endif

    printf("start init memwatch\n");
    mwInit();    

    signal(SIGUSR2, usr_signo);

    char *p = NULL;

    p = malloc(sizeof(char) * 100);

    printf("malloc success\n");
    

    for(;;)
    {
        pause();
    }

}
