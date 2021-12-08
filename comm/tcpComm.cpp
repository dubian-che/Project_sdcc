#include "api/tcpComm.h"
#include <string.h>
#include <stdio.h>

tcpComm::tcpComm()
{

}

// socket bind
U32 tcpComm::init()
{
    fd = socket(AF_INET,SOCK_STREAM, 0);
    if (fd == -1) {
        return TCP_SOCKET_ERR;
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(atoi("8080"));

    if(ROK != bind(fd,(struct sockaddr *)&addr,sizeof(addr))) {
        return TCP_BIND_ERR;
    }
    return ROK;
}

U32 tcpComm::tcplisten()
{
    if (listen(fd,5) != 0 ) {
        return TCP_LISTEN_ERR;
    }
    return ROK;
}

U32 tcpComm::work()
{
  // 接受客户端的连接。
  int clientfd;                  // 客户端的socket。
  int socklen = sizeof(struct sockaddr_in); // struct sockaddr_in的大小
  struct sockaddr_in clientaddr;  // 客户端的地址信息。
  clientfd = accept(fd, (struct sockaddr *)&clientaddr, (socklen_t *)&socklen);
  printf("客户端（%s）已连接。\n", inet_ntoa(clientaddr.sin_addr));
  char buffer[1024];
  while (1)
  {
    int iret;
    memset(buffer,0,sizeof(buffer));
    if ( (iret=recv(clientfd,buffer,sizeof(buffer),0))<=0) // 接收客户端的请求报文。
    {
       printf("iret=%d\n",iret); break;   
    }
    printf("接收：%s\n",buffer);
 
    strcpy(buffer,"ok");
    if ( (iret=send(clientfd,buffer,strlen(buffer),0))<=0) // 向客户端发送响应结果。
    { printf("send"); break; }
    printf("发送：%s\n",buffer);
  }
  return ROK;
}

