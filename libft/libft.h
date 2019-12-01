/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:14:44 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/01 11:11:18 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define ABS(value) (((value) < 0) ? -(value) : (value))

# define MAX_INT (2147483647)
# define MIN_INT (-MAX_INT - 1)
# define MAX_UINT (4294967295)

# define TRUE (1)
# define FALSE (0)
# define ERROR (-1)

# define BUFF_SIZE 16

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(const void *content, size_t content_size);
void			ft_lstadd(t_list **head, t_list *new);
void			ft_lstadd_back(t_list *head, t_list *new);

void			ft_lstdelone(t_list **link, void (*del)(void *, size_t));
void			ft_lstdel(t_list **head, void (*del)(void *, size_t));
void			ft_lstfree(void *content, size_t content_size);

void			ft_lstiter(t_list *link, void (*func)(t_list *link));
t_list			*ft_lstmap(t_list *head, t_list *(*func)(t_list *link));

/*
** Memory free
*/
void			ft_memdel(void **ptr);
void			ft_strdel(char **str);

/*
** Memory allocation
*/
void			*ft_realloc(void *ptr, size_t size);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
char			*ft_strdup(const char *str);
char			*ft_strsub(const char *str, unsigned int start, size_t len);
char			*ft_strjoin(const char *dst, const char *str);
char			*ft_strmap(const char *str, char (*f)(char));
char			*ft_strmapi(const char *str, char (*f)(unsigned int, char));
char			*ft_strtrim(const char *str);
char			**ft_strsplit(const char *str, char c);
int				*ft_range(int min, int max);
char			*ft_itoa(int nbr);
char			*ft_itoa_base(int number, int base);
int				ft_get_next_line(const int fd, char **line);

/*
** Memory modify, no allocation
*/
void			*ft_memset(void *dst, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);

/*
** Memory checking
*/
void			*ft_memchr(const void *dst, int c, size_t n);
int				ft_memcmp(const void *dst, const void *src, size_t n);

/*
** Standard output
*/
void			ft_putchar(char c);
void			ft_putnbr(int nbr);
void			ft_putstr(const char *str);
void			ft_putendl(const char *str);
void			ft_putstrn(const char *str, size_t n);
void			ft_putstrn_nulls(const char *str, const char c, size_t n);
void			ft_print2dstr(char **array, size_t count);

/*
** File output
*/
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putendl_fd(const char *str, int fd);
void			ft_putnbr_fd(int nbr, int fd);

/*
** Char checking
*/
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isspace(int c);
int				ft_atoi(const char *str);

/*
** String checking
*/
size_t			ft_strclen(const char *str, int c);
size_t			ft_strlen(const char *str);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_strequ(const char *str1, const char *str2);
int				ft_strnequ(const char *str1, const char *str2, size_t n);
char			*ft_strrchr(const char *str, int c);
char			*ft_strchr(const char *str, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);

/*
** String modify, no allocation
*/
void			ft_strclr(char *str);
void			ft_bzero(void *dst, size_t n);
char			*ft_strcpy(char *dst, const char *str);
char			*ft_strncpy(char *dst, const char *str, size_t len);
size_t			ft_strlcpy(char *dst, const char *str, size_t n);
char			*ft_strcat(char *dst, const char *str);
char			*ft_strncat(char *dst, const char *str, size_t n);
size_t			ft_strlcat(char *dst, const char *str, size_t dstsize);
void			ft_striter(char *str, void (*func)(char *));
void			ft_striteri(char *str, void (*func)(unsigned int, char *));
int				ft_toupper(int c);
int				ft_tolower(int c);
void			ft_strrev(char *str);

/*
** Math, no allocation
*/
unsigned int	ft_lcm(unsigned int a, unsigned int b);
unsigned int	ft_hcf(unsigned int a, unsigned int b);
unsigned int	ft_sqrt_int(unsigned int number);
unsigned int	ft_prime_nfactors(unsigned int number);

unsigned int	ft_issquare_int(unsigned int number);
unsigned int	ft_isprime(unsigned int number);

/*
** Math, allocation
*/
unsigned int	*ft_prime_factors(unsigned int number);

#endif
