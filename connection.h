//
// Created by mbien on 08.11.18.
//

#ifndef PUTHTTPD_CONNECTION_H
#define PUTHTTPD_CONNECTION_H

#include "http.h"

typedef enum {
    UNINITIALIZED,
    FAILURE,
    RUNNING,
    DOWN
} e_server_status;

typedef struct {
    int srv_socket;
    e_server_status status;
} s_tcp_server;


typedef struct {
    int fd;
    long lastAccess;
    s_buffer buffer;
    s_http_request *currentRequest;
    int requestQueue;
    s_http_response *currentResponse;
    int responseQueue;
} s_connection;

int accept_client_connection(s_tcp_server *srv_in, int epoll_fd);
long read_client_connection(s_connection *cli_socket);
int process_client_connection(s_connection *cli_socket);
int bind_server_socket(unsigned short port, s_tcp_server *srv_out);
void create_server_struct(s_tcp_server *srv_out);
int make_socket_nonblocking(int fd);
int close_client_connection(s_connection *cli_socket);
int close_server_socket(s_tcp_server *srv_in);
void safe_write(int socket, char *data, unsigned long size);

#endif //PUTHTTPD_CONNECTION_H