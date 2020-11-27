//
// Created by Administrator on 2020/11/20.
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

static void data_handle(void *sock_fd);
static printflush(const char * __restrict__ _Format,...);

int server_execute(int argc, char *argv[]) {
    int server_sockfd;//服务器端套接字
    int sockfd;//客户端套接字
    int len;
    int fd_temp;
    struct sockaddr_in my_addr;   //服务器网络地址结构体
    struct sockaddr_in client_addr; //客户端网络地址结构体
    int sin_size;
    /*
     * windows WSA
     */
    WSADATA wsaData;
    int nRet;
    if ((nRet = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0) {
        printflush("WSAStartup failed\n");
        exit(0);
    }
    /*创建服务器端套接字--IPv4协议，面向连接通信，TCP协议*/
    if ((server_sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        printflush("%d", WSAGetLastError());
        perror("socket");
        return 1;
    }

    //before bind(), set the attr of structure sockaddr.
    memset(&my_addr, 0, sizeof(my_addr)); //数据初始化--清零
    my_addr.sin_family = AF_INET; //设置为IP通信
    my_addr.sin_addr.s_addr = INADDR_ANY;//服务器IP地址--允许连接到所有本地地址上
    my_addr.sin_port = htons(SOCK_PORT); //服务器端口号

    /*将套接字绑定到服务器的网络地址上*/
    if (bind(server_sockfd, (struct sockaddr *) &my_addr, sizeof(struct sockaddr)) < 0) {
        perror("bind");
        return 1;
    }

    fd_temp = listen(server_sockfd, MAX_CONN_LIMIT);
    if (fd_temp < 0) {
        perror("listen");
        return 1;
    }

    while (1) {
        printflush("waiting for new connection...\n");
        pthread_t thread_id;
        sin_size = sizeof(struct sockaddr_in);

        //block here, until server accpets a new connection
        if ((sockfd = accept(server_sockfd, (struct sockaddr *) &client_addr, &sin_size)) < 0) {
            perror("accept");
            continue;
        }
        printflush("A new connection occurs!\n");
        if (pthread_create(&thread_id, NULL, (void *) (&data_handle), (void *) (&sockfd)) > 0) {
            perror("pthread_create");
            break;
        }
    }
    closesocket(server_sockfd);
    return 0;
}

static void data_handle(void *sock_fd){
    int len;
    int fd = *((int *) sock_fd);
    char buf[BUFFER_LENGTH];
    send(fd, "Welcome to my server\n", 21, 0);//发送欢迎信息
    int timeout = 3000; //3s
    int ret=setsockopt(fd, SOL_SOCKET, SO_SNDTIMEO, (char *) &timeout, sizeof(timeout));
    if (ret < 0) {
        perror("set timeout");
    }else {
        /*接收客户端的数据并将其发送给客户端--recv返回接收到的字节数，send返回发送的字节数*/
        while ((len = recv(fd, buf, BUFSIZ, 0)) > 0) {
            buf[len] = '\0';
            if(!strcmp(buf,"quit")){
                break;
            }else {
                printflush("%s", buf);
                if (send(fd, buf, len, 0) < 0) {
                    perror("write");
                    break;
                }
            }
        }
    }
    printflush("terminating current client_connection...\n");
    closesocket(fd);
    pthread_exit(NULL);
}

static printflush(const char * __restrict__ format,...){
    va_list marker;
    va_start(marker, format);
    vprintf(format, marker);
    va_end(marker);
    fflush(stdout);
}