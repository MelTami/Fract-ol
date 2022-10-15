/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:19:57 by mvavasso          #+#    #+#             */
/*   Updated: 2022/10/15 04:39:19 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 42

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nb, size_t size);
int		ft_isalnum(int n);
int		ft_isalpha(int n);
int		ft_isdigit(int n);
int		ft_isprint(int n);
int		ft_isascii(int n);
void	*ft_memchr(const void *str, int c, unsigned int n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memcpy(void *dest, const void *src, unsigned int n);
void	*ft_memmove(void *str1, void *str2, unsigned int n);
void	*ft_memset(void *str, int c, unsigned int n);
char	*ft_strchr(const char *str, int find);
char	*ft_strdup(const char *src);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcat(char *dest, const char *str, size_t size);
size_t	ft_strlcpy(char *dest, const char *str, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *str1, const char *str2, unsigned int n);
char	*ft_strnstr(const char *str, const char *find, size_t size);
char	*ft_strrchr(const char *str, int find);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_putchar(char c);
void	ft_free(char **str);
void	ft_putnbrbase(unsigned long num, char *base);
char	*get_next_line(int fd);
int		ft_printf(const char *s, ...);
int		ft_converthex(int hex, char *s);
int		ft_convertptr(void *ptr);
int		ft_convertint(int nb);
int		ft_convertu(unsigned int nb);
int		ft_puthex(unsigned int num, char *base);
int		ft_putbase(unsigned long num, char *base);
int		ft_isspace(int c);

#endif