#ifndef HELPER_FUNC_H
#define HELPER_FUNC_H
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#define BUFFSIZE 2048
#define INSTSIZE 1024

/**
 * struct set - singly linled list
 * @key: vaariable name in environment
 * @val: mapped value to key
 * @next: hold address to next node
 *
 * Description: singly linked list node struct
 */
struct set
{
	char *key;
	char *val;
	struct set *next;
};
typedef struct set envar;
extern char **environ;
ssize_t _getline(char *buff, size_t *num, int fildes);
size_t str_len(char *s);
char *str_cpy(char *des, char *src);
char *str_dup(char *s);
char *_strcat(char *dest, char *src);
void child(char *route, char *args[], char **ens);
int print_en(void);
void prompt(void);
void sig_handle(int sig);
int str_cmp(char *s1, char *s2);
void start_child(char **instruct);
int check_cmd(char **cmds, char *prgnm);
int cdry(char *cmds);
void exit_msg(char *progmn, char **cmdname);
int _strncmp(char *str1, char *str2, size_t n);
void _free(char **ptr);
char *_getenv(char *name, char *dupe);
int a_toi(char *str);
size_t numstr(char *str, char sep);
void string_split(char *str, char *sep, ssize_t len, char **instruct);
#endif /* HELPER_FUNC_H */
