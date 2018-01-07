#ifndef _FT_TOOLS_H
# define _FT_TOOLS_H

#include <string.h>
#include <inttypes.h>

# define LONG_INT_MAX 9223372036854775807

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

char			*spc_string(char **str, size_t new_len, char filler, char side);
char			*easy_joiner(char *str, char *fst, char *scd);
char			*str_add_prefix(char **str, char c);
void			ft_strappend(char **str, char c);

char			*ft_itoa(const int val);
char			*ft_ltoa(const long int val);
char			*ft_lltoa(const long long int val);
char			*ft_ulltoa(const unsigned long long int val);
char			*ft_uimtoa(const uintmax_t val);
char			*ft_uimtoa_hlp(const uintmax_t val, int sign);
void			ft_lstaddelem(t_list **lst, void **content, size_t content_size);
size_t			ft_lstlen(const t_list *lst);

int				ft_abs(int val);

char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
char			*ft_strnew(const size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
char			*ft_strnew(const size_t len);
void			ft_strdel(char **str);
void			ft_putstr(char const *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);

int				ft_isdigit(int c);
int				ft_atoi(const char *str);
char			*ft_strchr(const char *s, int c);

void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memalloc(size_t size);

void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstappend(t_list **lst, t_list *new);
t_list			*ft_lstnew(void const *content, size_t content_size);

#endif
