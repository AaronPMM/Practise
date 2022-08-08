//广播数据例子
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30

void error_handling(char *message);

int main(int argc, char *argv[])
{
    int send_sock;
    struct sockaddr_in broad_ar;
    FILE *fp;
    char buf[BUF_SIZE];
    int so_brd = 1; //将 SO_BROADCAST 设置为1，意味着可以进行数据广播

    if(argc != 3)
    {
        printf("Usage : %s <Broadcast IP> <PORT>\n", argv[0]);
        exit(1);
    }

    send_sock = socket(PF_INET, SOCK_DGRAM, 0);
    memset(&broad_ar, 0, sizeof(broad_ar));
    broad_ar.sin_family = AF_INET;
    broad_ar.sin_addr.s_addr = inet_addr(argv[1]);
    broad_ar.sin_port = htons(atoi(argv[2]));

    setsockopt(send_sock, SOL_SOCKET, SO_BROADCAST, (void *)&so_brd, sizeof(so_brd));

    if((fp = fopen("news.txt", "r")) == NULL)
    {
        error_handling("fopen() error");
    }

    while (!feof(fp))
    {
        fgets(buf, BUF_SIZE, fp);
        sendto(send_sock, buf, strlen(buf), 0,
                (struct sockaddr*)&broad_ar, sizeof(broad_ar));

        sleep(2);
    }

    close(send_sock);

    return 0;
    
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}