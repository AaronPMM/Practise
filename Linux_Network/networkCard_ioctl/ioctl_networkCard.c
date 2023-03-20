#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdbool.h>
#define PRINTF_LOG printf
#define MAX_INTERFACE 100
void port_status(unsigned int flags)
{
    if(flags & IFF_UP)
    {
        PRINTF_LOG("is up\n");
    }

    if(flags & IFF_BROADCAST)
    {
        PRINTF_LOG("is broadcast\n");
    }

    if(flags & IFF_LOOPBACK)
    {
        PRINTF_LOG("is loop back\n");
    }

    if(flags & IFF_POINTOPOINT)
    {
        PRINTF_LOG("is point to point\n");
    }

    if(flags & IFF_RUNNING)
    {
        PRINTF_LOG("is runing\n");
    }

    if(flags & IFF_PROMISC)
    {
        PRINTF_LOG("is promisc\n");
    }
}


int set_if_flags(char *pif_name, int sock, int status, int set)
{
    struct ifreq ifr;
    int ret = 0;
             
    strncpy(ifr.ifr_name, pif_name, strlen(pif_name) + 1);
    ret = ioctl(sock, SIOCGIFFLAGS, &ifr);
    if (ret) {
        return -1;
    }

    /* set or clean */
    if (set) {
        ifr.ifr_flags |= status;
    }
    else {
        ifr.ifr_flags &= ~status;
    }

    /* set flags */
    ret = ioctl(sock, SIOCSIFFLAGS, &ifr);
    if (ret) {
        return -1;
    }

    return 0;
}

int get_if_info(int fd)
{
    struct ifreq buf[MAX_INTERFACE];
    struct ifconf ifc;
    int ret = 0;
    int if_num = 0;

    ifc.ifc_len = sizeof(buf);
    ifc.ifc_buf = (caddr_t)buf;

    ret = ioctl(fd, SIOCGIFCONF, (char *)&ifc);
    if (ret) {
        PRINTF_LOG("get if config info failed");
        return -1;
    }

    /* 网口总数 ifc.ifc_len 应该是一个出入参数 */
    if_num = ifc.ifc_len / sizeof(struct ifreq);
    PRINTF_LOG("interface num is interface = %d\n", if_num);

    while (if_num-- > 0) {
        PRINTF_LOG("net device: %s\n", buf[if_num].ifr_name);
        /* 获取第n个网口信息 */
        ret = ioctl(fd, SIOCGIFFLAGS, (char *)&buf[if_num]);
        if (ret)
            continue;

        /* 获取网口状态 */
        port_status(buf[if_num].ifr_flags);

        /* 获取当前网卡的ip地址 */
        ret = ioctl(fd, SIOCGIFADDR, (char *)&buf[if_num]);
        if (ret) {
            continue;
        }

        PRINTF_LOG("IP address is: \n%s\n", inet_ntoa(((struct sockaddr_in *)(&buf[if_num].ifr_addr))->sin_addr));

        /* 获取当前网卡的mac */
        ret = ioctl(fd, SIOCGIFHWADDR, (char *)&buf[if_num]);
        if (ret) {
            continue;
        }

        PRINTF_LOG("%02x:%02x:%02x:%02x:%02x:%02x\n\n",
                (unsigned char)buf[if_num].ifr_hwaddr.sa_data[0],
                (unsigned char)buf[if_num].ifr_hwaddr.sa_data[1],
                (unsigned char)buf[if_num].ifr_hwaddr.sa_data[2],
                (unsigned char)buf[if_num].ifr_hwaddr.sa_data[3],
                (unsigned char)buf[if_num].ifr_hwaddr.sa_data[4],
                (unsigned char)buf[if_num].ifr_hwaddr.sa_data[5]);
    }
}

int CheckLink(char *ifname) {
    int state = -1;
    int socId = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (socId < 0) 
        PRINTF_LOG("Socket failed. Errno = %d\n", errno);

    struct ifreq if_req;
    (void) strncpy(if_req.ifr_name, ifname, sizeof(if_req.ifr_name));
    int rv = ioctl(socId, SIOCGIFFLAGS, &if_req);
    close(socId);

    if ( rv == -1)
        PRINTF_LOG("Ioctl failed. Errno = %d\n", errno);

    return (if_req.ifr_flags & IFF_UP) && (if_req.ifr_flags & IFF_RUNNING);
}

int network_iNetowrkCardDetection(void)
{
    struct ifreq ifr;
    struct ifconf ifc;
    char buf[2048];
    //int success = 0;
    //bool bNetworkCard = false;
    bool bNetworkCard_lo = false;
    bool bNetworkCard_eth0 = false;
    bool bNetworkCard_wlan0 = false;

    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (sock == -1)
    { 
        PRINTF_LOG("socket error\n");
        return -1;
    }

    ifc.ifc_len = sizeof(buf);
    ifc.ifc_buf = buf;
    if (ioctl(sock, SIOCGIFCONF, &ifc) == -1)
    {
        PRINTF_LOG("ioctl error\n");
        return -1;
    }

    struct ifreq* it = ifc.ifc_req;
    const struct ifreq* const end = it + (ifc.ifc_len / sizeof(struct ifreq));
    const int num =  ifc.ifc_len / sizeof(struct ifreq);
    PRINTF_LOG("num %d \n", ifc.ifc_len / sizeof(struct ifreq));
    char szMac[64];
    int count = 0;
    for (; it != end; ++it)
    {
        strcpy(ifr.ifr_name, it->ifr_name);
        if (ioctl(sock, SIOCGIFFLAGS, &ifr) == 0)
        {
            //if (! (ifr.ifr_flags & IFF_LOOPBACK))
            if(!(ifr.ifr_flags & IFF_PROMISC))
            { // don't count loopback
                if (ioctl(sock, SIOCGIFHWADDR, &ifr) == 0)
                {
                    count ++ ;
                    unsigned char * ptr ;
                    ptr = (unsigned char  *)&ifr.ifr_ifru.ifru_hwaddr.sa_data[0];
                    snprintf(szMac,64,"%02X:%02X:%02X:%02X:%02X:%02X",*ptr,*(ptr+1),*(ptr+2),*(ptr+3),*(ptr+4),*(ptr+5));
                    PRINTF_LOG("%d,Interface name : %s , Mac address : %s \n",count,ifr.ifr_name,szMac);

                    port_status(ifr.ifr_flags);

                    char ip[20];

                    strcpy(ip, inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));

                    PRINTF_LOG("%s ip %s", ifr.ifr_name, ip);

                    if(strcmp(ifr.ifr_name, "lo") == 0)
                    {
                        bNetworkCard_lo = true;
                    }
                    else if(strcmp(ifr.ifr_name, "eth0") == 0)
                    {
                        bNetworkCard_eth0 = true;
                    }
                    else if(strcmp(ifr.ifr_name, "wlan0") == 0)
                    {
                        bNetworkCard_wlan0 = true;
                    }
                }
            }
        }
        else
        {
            PRINTF_LOG("get mac info error\n");
            return -1;
        }
    }

    PRINTF_LOG("lo %d eth0 %d wlan0 %d\n", bNetworkCard_lo, bNetworkCard_eth0, bNetworkCard_wlan0);
    if((bNetworkCard_lo == true) && ((bNetworkCard_eth0 == true) || (bNetworkCard_wlan0 == true)))
    {
        return 1;
    }
    else
    {
        return -1;

    }

    return 0;
}

void main(void)
{
    while(1) {
        //network_iNetowrkCardDetection();
        
        int fd;

        fd = socket(AF_INET, SOCK_DGRAM, 0);
        if(fd > 0)
        {
            get_if_info(fd);

            close(fd);
        }

        sleep(3);
    }
}

