#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


char *repeat(char *key, int keylen, int msglen);
char *crypt(char *msg, int msglen, char *key, int keylen);
void print_bytes(char *str, int length);
int file_exists(char *path);
