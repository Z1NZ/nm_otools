
#ifndef FT_NM_H
#include <sys/stat.h>
#include <string.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <stdio.h>// printf("%s\n", );



void	ft_put_out_test(unsigned long nsyms, unsigned long symoff, unsigned long stroff, char *ptr);

void    ft_openner(char *argv);

/*
** CORE
*/

void	ft_core(char *ptr);
void	ft_core_64(char *ptr);
void	ft_core_32(char *ptr);
void	ft_core_mmap(int fd, struct stat *buff);

/*
** TOOLS
*/
void	ft_putnbr(int n);
void	pri_addr(unsigned long long number);
void	ft_put_n_char(char *ptr, size_t nb);
void	ft_error_st_mode(mode_t st_mode, char *name);
void	ft_error_errno(char * ptr, char *name);
void	ft_putstr(char *s);
void	ft_putstr_fd(const char *const s, int fd);
size_t	ft_strlen(const char *const s);

#endif
