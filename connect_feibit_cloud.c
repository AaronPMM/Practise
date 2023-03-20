#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define BUILD_UINT16(loByte, hiByte) \
          ((uint16_t)(((loByte) & 0x00FF) + (((hiByte) & 0x00FF) << 8)))

#define FEIBIT_CLOUD_DOMAIN_NAME "www.fbeecloud.com"
#define FEIBIT_CLOUD_POINT 8090

int feibitCloud_LoginMessage[] = {0x40, 0x00, 0x50, 0x00, 0x3a, 0x00, 0x5b, 0x46, 0x65, 0x62, 0x69, 0x74, 0x20, 0x46, 0x43, 0x6c, 0x6f, 0x75, 
                                    0x64, 0x20, 0x53, 0x65, 0x72, 0x76, 0x65, 0x72, 0x20, 0x56, 0x32, 0x2e, 0x30, 0x2e, 0x30, 0x5d, 0x0d, 0x0a, 0x5b, 0x4e, 0x6f, 0x72, 
                                    0x6d, 0x61, 0x6c, 0x20, 0x53, 0x6f, 0x63, 0x6b, 0x65, 0x74, 0x20, 0x4d, 0x6f, 0x64, 0x65, 0x5d, 0x0d, 0x0a, 0x4c, 0x6f, 0x67, 0x69, 0x6e, 0x3a};
                                
                                
uint8_t acRecvBuf[1024] = {0};

int network_connect_feibit_cloud(int *serv_fd);
void network_recv_from_cloud(int fd);
int network_message_handler(uint8_t *message);

int main(void)
{

    int ret, serv_fd = 0;

    ret = network_connect_feibit_cloud(&serv_fd);
    if(ret == -1)
    {
        printf("connect cloud fail\r\n");
    }

    //send login message
    //network_send_message_to_cloud();

    for(;;)
    {
        network_recv_from_cloud(serv_fd);

    }    

}

int network_connect_feibit_cloud(int *serv_fd)
{
    int ret = 0;
    int fd;
    struct hostent *host_ptr;
    struct sockaddr_in addr_in;
    struct sockaddr_in serv_addr;

    //解析域名获取 IP 地址
    host_ptr = gethostbyname(FEIBIT_CLOUD_DOMAIN_NAME);

    if(host_ptr == NULL)
    {
        printf("resolve domain name fail\r\n");
        return -1;
    }

    //创建 socket
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd == -1)
    {
        printf("creat socket fail\r\n");
        return -1;
    }


    //connect feibit cloud
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(FEIBIT_CLOUD_POINT);
    serv_addr.sin_addr.s_addr = *(in_addr_t*)host_ptr->h_addr_list[0];

    ret = connect(fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if(ret == -1)
    {
        printf("connect fail, %s\r\n", strerror(errno));
        close(fd);
    }
    else
    {
        *serv_fd = fd;
        printf("connect success\r\n");
    }

    return ret;
}

void network_recv_from_cloud(int fd)
{
    int str_len;
    str_len = read(fd, acRecvBuf,sizeof(acRecvBuf));
    if(str_len > 0)
    {
        int index;
        printf("recv: ");
        for(index = 0; index < str_len; index++)
            printf("%02x ", acRecvBuf[index]);

        printf("\r\n");

        network_message_handler(acRecvBuf);
    }
}

int network_send_message_to_cloud(int fd, char *message, int length)
{
    write(fd, message, length);
}

int network_message_handler(uint8_t *message)
{
    uint8_t message_length = message[0];
    uint16_t message_type = BUILD_UINT16(message[2], message[3]);
    printf("message type %d\r\n", message_type);

    switch(message_type)
    {
        case 80:
            printf("log request\r\n");
            break;
    }
}

int network_send_login_reply(int fd, char *gateway_name, char *password)
{
    // | length L | length H | commadn type L | commadn type H | message length L | message length H | gateway name | kong ge | password |  
    network_send_message_to_cloud();
}