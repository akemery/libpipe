#include <unistd.h>
#include "pipe.h"

int fd[2];
int init = 0;

int pipe_init(int writer){
  int ret = 0;
  if(!init){
    ret = pipe(fd);
    init = 1;
  }
  if(ret<0)
    return ret;
  ret = writer ? fd[1] : fd[0];
  return ret;
}

size_t pipe_send(int pd, char* buff, size_t len){
  if(pd!=fd[1])
    return -1;
  return write(pd, buff, len);
}

size_t pipe_recv(int pd, char *buff, size_t len){
  if(pd!=fd[0])
    return -1;
  return read(pd, buff, len);
}

int pipe_close(void){
   return (close(fd[0] || close(fd[1])));
}

int pipe_get_read_fd(void){
  return fd[0];
}

int pipe_get_write_fd(void){
  return fd[1];
}
