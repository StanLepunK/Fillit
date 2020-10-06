/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:06:11 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/25 15:17:28 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

# define FALSE 0
# define TRUE 1

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_bzero(void *s, size_t len);

void			*ft_memset(void *b, int c, size_t len);

void			*ft_memcpy(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *src, int c, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t len);

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t len);
size_t			ft_strlcat(char *dst, const char *src, size_t len);
char			*ft_strchr(const char *src, int c);
char			*ft_strrchr(const char *src, int c);
char			*ft_strstr(const char *src, const char *find);
char			*ft_strnstr(const char *src, const char *find, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t len);

int				ft_atoi(const char *str);

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

void			*ft_memalloc(size_t len);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t len);
void			ft_strdel(char **as);
void			ft_strclr(char *src);
void			ft_striter(char *src, void (*f)(char *));
void			ft_striteri(char *src, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *src, char (*f)(char));
char			*ft_strmapi(char const *src, char(*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t len);
char			*ft_strsub(char const *src, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *src);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int nbr);

void			ft_putchar(char c);
void			ft_putstr(char const *src);
void			ft_putendl(char const *src);
void			ft_putnbr(int nbr);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *src, int fd);
void			ft_putendl_fd(char const *src, int fd);
void			ft_putnbr_fd(int nbr, int fd);

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

char			*r_copy_from_index(const char *src, int start, int len);
char			*r_copy_from_char(const char *src, int c);
int				r_upper_is(int c);
int				r_lower_is(int c);
int				r_space_is(int c);

#endif
