/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 19:20:17 by srabah            #+#    #+#             */
/*   Updated: 2017/05/21 19:20:23 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTOOL_H
# define FT_OTOOL_H
# include <sys/stat.h>
# include <string.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <stdlib.h>
# include <ar.h>
# include <stdio.h>

typedef struct		s_list
{
	char			*ptr;
	char			type;
	char			pad[7];
	uint64_t		n_value;
	struct s_list	*next;
}					t_list;

typedef struct		s_count
{
	unsigned char	text;
	unsigned char	data;
	unsigned char	bss;
	unsigned char	k;
}					t_count;

typedef	struct		s_llib
{
	char			*ptr;
	unsigned long	offset;
	struct s_llib	*next;
}					t_llib;

typedef struct		s_file_info
{
	struct stat		data_stat;
	char			*data_file;
	char			*filename;
	uint64_t		fat;
}					t_file_info;

# define ERROR		" The file was not recognized as a valid object file\n\n"

int					ft_openner(t_file_info info);
/*
** 	PRINTER
*/
void				simple_print_64(t_list *ptr);
void				simple_print_32(t_list *ptr);
void				print_lib(t_file_info info, t_llib *lib);

/*
** CORE
*/

int					ft_core(t_file_info info);
int					ft_core_fat(t_file_info info);
int					ft_core_fat_litle(t_file_info info);
int					ft_core_64(t_file_info info);
int					ft_core_64_litle(t_file_info info);
int					ft_core_32(t_file_info info);
int					ft_core_32_litle(t_file_info info);
int					ft_core_mmap(int fd, t_file_info info);
int					find_arch(t_file_info info);
void				ft_print_sub_arm(cpu_subtype_t sub);
void				ft_print_sub_ppc(cpu_subtype_t sub);
void				ft_print_arch(cpu_type_t type, cpu_subtype_t sub);
int					ft_core_static_lib(t_file_info info);

/*
** TOOLS
*/
void				ft_print_hexa_uchar(unsigned char number);
void				free_lib(t_llib *lib);
void				ft_sort_lib(t_llib *lib);
void				ft_push_mod_back(t_llib *lib, t_llib *tmp);
t_llib				*ft_add_mod(t_file_info info, t_llib *lib, uint32_t len);
int					ft_atoi(const char *str);
int					ft_isspace(int c);
int					ft_isdigit(int c);
char				*ft_strstr(char *str, char *to_find);
void				ft_free_list(t_list *head);
void				ft_free_list_litle(t_list *head);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strrev(char *str);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*reverse(char *ptr, size_t len);
void				ft_error_recognized(const char *ptr);
char				get_type(struct nlist *nl, t_count count_f);
char				get_type_64(struct nlist_64 *nl, t_count count);
int					ft_strcmp(char *s1, char *s2);
void				sort_list(t_list *ptr);
void				ft_list_swap(t_list *a, t_list *b);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
char				ft_islower(char c);
char				ft_toupper(char c);
void				ft_putnbr(int n);
void				ft_print_hexa_64(unsigned long long number);
void				ft_print_hexa_32(unsigned long number);
void				ft_put_n_char(char *ptr, size_t nb);
void				ft_error_st_mode(mode_t st_mode, char *name);
void				ft_error_errno(char *ptr, char *name);
void				ft_putstr(char *s);
void				ft_putstr_fd(const char *const s, int fd);
size_t				ft_strlen(const char *const s);

#endif
