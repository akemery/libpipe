int pipe_init(int writer);
size_t pipe_send(int pd, char*buff, size_t len);
size_t pipe_recv(int pd, char *buff, size_t len);
int pipe_close(void);
int pipe_get_read_fd(void);
int pipe_get_write_fd(void);
