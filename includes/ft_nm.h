
#ifndef FT_NM_H
#include <sys/stat.h>
#include <string.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <stdio.h>// printf("%s\n", );

typedef struct		s_list
{
	char			*ptr;
	char			type;
	char			pad[7];
	uint64_t 		n_value;
	struct s_list	*next;
}					t_list;

void	ft_put_out_test(unsigned long nsyms, unsigned long symoff, unsigned long stroff, char *ptr);
void	ft_nlist(unsigned long nsyms, unsigned long symoff, unsigned long stroff, char *ptr);
void    ft_openner(char *argv);





/*
** 	PRINTER
*/
void	simple_print_64(t_list *ptr);
void	simple_print_32(t_list *ptr);

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
char	get_type(struct nlist *sym);
char	get_type_64(struct nlist_64 *sym);
int		ft_strcmp(char *s1, char *s2);
void	sort_list(t_list *ptr);
void	ft_list_swap(t_list *a, t_list *b);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memalloc(size_t size);
char	ft_islower(char c);
char	ft_toupper(char c);
void	ft_putnbr(int n);
void	ft_print_hexa_64(unsigned long long number);
void	ft_print_hexa_32(unsigned long number);
void	ft_put_n_char(char *ptr, size_t nb);
void	ft_error_st_mode(mode_t st_mode, char *name);
void	ft_error_errno(char * ptr, char *name);
void	ft_putstr(char *s);
void	ft_putstr_fd(const char *const s, int fd);
size_t	ft_strlen(const char *const s);

#endif
