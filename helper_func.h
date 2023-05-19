#ifndef HELPER_FUNC_H
#define HELPER_FUNC_H
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;
ssize_t _getline(char **buff, size_t *num, int fildes);
size_t str_len(char *s);
char *str_cpy(char *des, char *src);
char *str_dup(char *s);
char *_strcat(char *dest, const char *src);
void child(char *route, char *args[], char **ens);
int print_en(void);
void prompt(void);
int str_cmp(char *s1, char *s2);
void start_child(char **instruct);
int check_cmd(char **cmds);
int cdry(char *cmds);
char *_getenv(const char *name);
size_t numstr(char *str, char sep);
char **string_split(char *str, char *sep, ssize_t len);
#endif /* HELPER_FUNC_H */
