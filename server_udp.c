//
// Created by Administrator on 2020/11/26.
//

//[linux]
//#include <stdio.h>
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>

//[windows]
#include <winsock.h>
#include <stdio.h>
#include <pthread.h>

#define SOCK_PORT 8000
#define BUFFER_LENGTH  1024
#define MAX_CONN_LIMIT 512

static printflush(const char * __restrict__ _Format,...);

int server_udp_execute(int argc, char *argv[]){
    int server_sockfd;
    int len;
    struct sockaddr_in my_addr;   //服务器网络地址结构体
    struct sockaddr_in remote_addr; //客户端网络地址结构体
    int sin_size;
    char buf[2];  //数据传送的缓冲区
    memset(&my_addr,0,sizeof(my_addr)); //数据初始化--清零
    my_addr.sin_family=AF_INET; //设置为IP通信
    my_addr.sin_addr.s_addr=INADDR_ANY;//服务器IP地址--允许连接到所有本地地址上
    my_addr.sin_port=htons(8000); //服务器端口号

    /*
     * windows WSA
     */
    WSADATA wsaData;
    int nRet;
    if ((nRet = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0) {
        printflush("WSAStartup failed\n");
        exit(0);
    }

    /*创建服务器端套接字--IPv4协议，面向无连接通信，UDP协议*/
    if((server_sockfd=socket(PF_INET,SOCK_DGRAM,0))<0)
    {
        perror("socket");
        return 1;
    }

    /*将套接字绑定到服务器的网络地址上*/
    if (bind(server_sockfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr))<0)
    {
        perror("bind");
        return 1;
    }

    printflush("waiting for a packet...\n");
    while (1) {
        sin_size=sizeof(struct sockaddr_in);
        pthread_t thread_id;

        /*接收客户端的数据并将其发送给客户端--recvfrom是无连接的*/
        if((len=recvfrom(server_sockfd,buf,2,0,(struct sockaddr *)&remote_addr,&sin_size))<0)
        {
            perror("recvfrom");
            return 1;
        }
//        printflush("received packet from %s:\n",inet_ntoa(remote_addr.sin_addr));
        buf[len]='\0';
        printflush("%s",buf);
    }
    closesocket(server_sockfd);
    return 0;
}

static printflush(const char * __restrict__ format,...){
    va_list marker;
    va_start(marker, format);
    vprintf(format, marker);
    va_end(marker);
    fflush(stdout);
}