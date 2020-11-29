#include <stdio.h>
#include <string.h>
#include "pipe.h"

#define BUFF_SIZE 1024

int main(int argc, char *argv[]){
  char write_buff[BUFF_SIZE] = "Bonjour les amis de korogo";
  char read_buff[BUFF_SIZE];
  int readfd, writefd;
  int ret = pipe_init(1);
  if(ret < 0) 
    perror("Erreur d'initialisation du pipe");
  memset(read_buff, '0', BUFF_SIZE);
  readfd = pipe_get_read_fd();
  writefd = pipe_get_write_fd();
  if((ret = pipe_send(writefd, write_buff, 13)) < 0)
    perror("Erreur d'écriture dans le pipe");
  if((ret = pipe_recv(readfd, read_buff, 10)) < 0)
    printf("Erreur de lecture à partir du pipe");
 
  read_buff[ret] = '\0';
  printf("%s\n", read_buff);
  pipe_close();
}
