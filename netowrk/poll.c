#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <poll.h>
#include <errno.h>

#define MAXLIEN 100
#define OPEN_MAX 5

#define SERV_PORT 10086

#if 0
struct pollfd{
    int fd; //监听的文件描述符
    short events; //待监听的文件描述符对应的监听事件
    short revents; //返回事件，传入时给0，如果满足对应事件，返回非0
};
#endif

int main(int argc, char *agrv[])
{
    int i, maxi, listenfd, connfd, sockfd;
    int nready;
    ssize_t n;
    char buf[MAXLIEN];

    socklen_t clilen;
    struct pollfd client[OPEN_MAX];
    struct sockaddr_in cliaddr, servaddr;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        printf("bind() error\n");
        exit(1);
    }

    if(listen(listenfd, OPEN_MAX) == -1)
    {
        printf("listen() error\n");
        exit(1);
    }

    client[0].fd = listenfd;
    client[0].events = POLLRDNORM;
    for(i = 1; i < OPEN_MAX; i++)
    {
        client[i].fd = -1;
    }

    maxi = 0;

    for(;;)
    {
        //poll 事件轮询机制
        nready = poll(client, maxi + 1, 1000);

        //监听端口10086 的连接
        if(client[0].revents & POLLRDNORM)
        {
            //new client connection
            clilen = sizeof(cliaddr);
            connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);

            for(i = 1; i < OPEN_MAX; i++)
            {
                if(client[i].fd < 0)
                {
                    //save descriptor
                    client[i].fd = connfd;  
                    printf("save descripor client[%d] %d\n", i, client[i].fd);
                    break;
                }
            }

            if(i == OPEN_MAX)
            {
                printf("too many clients\n");
            }

            client[i].events = POLLRDNORM;

            if(i > maxi)
            {
                // max index in client[] array
                maxi = i;
            }

            if(--nready <= 0)
            {
                //no more readable descriptors
                continue;
            }

        }

        for(i = 0; i <= maxi; i++)
        {
            //check all clients for data
            if((sockfd = client[i].fd) < 0)
            {
                continue;
            }

            if(client[i].revents & (POLLRDNORM | POLLERR))
            {
                if((n = read(sockfd, buf, MAXLIEN)) < 0)
                {
                    if(errno == ECONNRESET)
                    {
                        //connection reset by client
                        close(sockfd);
                        client[i].fd = -1;
                        printf("connection reset by client\n");
                    }
                    else
                    {
                        printf("read error\n");
                    }
                }
                else if(n == 0)
                {
                    //connection closed by client
                    close(sockfd);
                    client[i].fd = -1;
                    printf("connection closed by client\n");
                }
                else
                {
                    write(sockfd, buf, n);
                }

                if(--nready <= 0)
                {
                    //no more readable descriptors
                    break;
                }
            }
        }

    }
}