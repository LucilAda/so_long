/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:23:55 by lufreder          #+#    #+#             */
/*   Updated: 2024/07/18 16:22:55 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strcpy(char *dest, char *src);
int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	*ft_calloc(size_t count, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
t_list	*ft_lstnew(void	*content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
int		ft_lstsize(t_list *lst);

/*GET_NEXT_LINE*/
char	*store_reading(char *storage, char *buffer);
char	*read_the_line(int fd, char *buffer, char *tmp);
char	*extract(char *line);
char	*get_next_line(int fd);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
size_t	ft_strlen_gnl(const char	*s);
char	*ft_strdup_gnl(const char *s1);
char	*ft_strjoin_gnl(const char *s1, const char *s2);
char	*ft_strchr_gnl(const char *s, int c);

/*FT_PRINTF*/
int		ft_printf(const char *s, ...);
void	ft_putchar(char c, int *count);
void	ft_putnbr_hex_ptr(unsigned long nbr, int *count);
void	ft_putnbr_hex_xlo(unsigned int nb, int *count);
void	ft_putnbr_hex_xup(unsigned int nb, int *count);
void	ft_putnbr_u(unsigned int nb, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putptr(void *ptr, int *count);
void	ft_putstr(char *str, int *count);
#endif