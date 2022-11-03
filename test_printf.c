#include <stdio.h>
#include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_toupper(int x)
{
	if (!(x >= 'a' && x <= 'z'))
		return (x);
	return (x - 32);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		n = 0 - n;
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

static char	*ft_reverse(char *str)
{
	char	*ptr;
	int		slen;
	int		i;

	slen = ft_strlen(str);
	ptr = (char *) malloc(slen + 1);
	i = 0;
	while (slen > 0)
	{
		ptr[i] = str[slen - 1];
		i++;
		slen--;
	}
	ptr[i] = '\0';
	return (ptr);
}

static void ft_divmod(unsigned long nb, unsigned long *div, unsigned long *mod)
{
    if (nb < 0)
	{
		*mod = -nb % 16;
        *div = -nb / 16;
	}
	else
	{
		*mod = nb % 16;
        *div = nb / 16;
	}
}

static char *ft_allocation(unsigned long nb, char *ptr)
{
    int i;
    unsigned long div;
	unsigned long mod;

    i = 1;
    ft_divmod(nb, &div, &mod);
	while (div > 0)
	{
		i++;
		div = div / 16;
	}
    ptr = (char *) malloc(i + 1);
	if (!ptr)
		return (0);
    return (ptr);
}

static char	*ft_hexa(unsigned long nb)
{
	char			*lh;
	char			*conv;
	int				i;
	unsigned long	div;
	unsigned long	mod;

	lh = "0123456789abcdef";
	conv = ft_allocation(nb, conv);
	ft_divmod(nb, &div, &mod);
    i = 0;
	while(div > 0)
	{
		conv[i++] = lh[mod];
		mod = div % 16;
		div = div / 16;
	}
	conv[i++] = lh[mod];
    if (nb < 0)
	    conv[i++] = '-';
	conv[i] = '\0';
	conv = ft_reverse(conv);
	return (conv);
}

char	*ft_putadd(unsigned long add)
{
	char	*s1;
	char	*s2;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	s1 = ft_hexa(add);
	l = ft_strlen(s1) + 3;
	s2 = (char *) malloc(l * sizeof(char));
	s2[i++] = '0';
	s2[i++] = 'x';
	while (i < l)
		s2[i++] = s1[j++];
	return (s2);
}

static int ft_div(unsigned int nb)
{
    unsigned int div;

    if (nb < 0)
        div = -nb / 16;
    else
        div = nb / 16;
    return (div);
}

static int ft_mod(unsigned int nb)
{
    unsigned int mod;

    if (nb < 0)
        mod = -nb % 16;
    else
        mod = nb % 16;
    return (mod);
}

char	*ft_putlhexa(unsigned int nb)
{
	char			*lh;
	char			*conv;
	int				i;
	unsigned int	div;
	unsigned int	mod;

	lh = "0123456789abcdef";
	conv = ft_allocation(nb, conv);
	div = ft_div(nb);
    mod = ft_mod(nb);
    i = 0;
	while(div > 0)
	{
		conv[i++] = lh[mod];
		mod = div % 16;
		div = div / 16;
	}
	conv[i++] = lh[mod];
    if (nb < 0)
	    conv[i++] = '-';
	conv[i] = '\0';
	conv = ft_reverse(conv);
	return (conv);
}

char	*ft_putuhexa(unsigned int nb)
{
	char			*conv;
	int		i;

	i = 0;
	conv = ft_putlhexa(nb);
	while (conv[i])
		conv[i++] = ft_toupper(conv[i]);
	return (conv);
}

static int	ft_ndigit(unsigned int n)
{
	unsigned int	temp;
	int	j;

	j = 1;
	temp = n;
	while (temp / 10 > 9)
	{
		temp = temp / 10;
		j++;
	}
	j++;
	if (temp / 10 == 0)
		j--;
	return (j);
}

static char	*ft_pnbr(char *ptr, unsigned int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = ft_ndigit(n);
	k = j;
	while (n / 10 > 9)
	{
		ptr[j - 1] = n % 10 + '0';
		n = n / 10;
		j--;
	}
	ptr[j - 1] = n % 10 + '0';
	if (n / 10 != 0)
		ptr[j - 2] = n / 10 + '0';
	ptr[k] = '\0';
	return (ptr);
}

static char	*ft_znbr(char *ptr)
{
	ptr[0] = '0';
	ptr[1] = '\0';
	return (ptr);
}

char	*ft_putunsi(unsigned int n)
{
	char	*ptr;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = ft_ndigit(n);
	k = j;
	if (n == 0)
		ptr = (char *)malloc(2 * sizeof(char));
	else
		ptr = (char *)malloc((j + 1) * sizeof(char));
	if (!ptr)
		return (0);
	if (n == 0)
		ptr = ft_znbr(ptr);
	else
		ptr = ft_pnbr(ptr, n);
	return (ptr);
}

static int	ndigit(int n)
{
	int	temp;
	int	j;

	j = 1;
	temp = n;
	if (temp == -2147483648)
		return (11);
	if (temp < 0)
		temp = 0 - temp;
	while (temp / 10 > 9)
	{
		temp = temp / 10;
		j++;
	}
	j++;
	if (n < 0)
		j++;
	if (temp / 10 == 0)
		j--;
	return (j);
}

static char	*nnbr(char *ptr, int n)
{
	int	i;
	int	j;

	i = 0;
	j = ndigit(n);
	ptr[j] = '\0';
	ptr[0] = '-';
	if (n == -2147483648)
	{
		ptr[1] = '2';
		n = -147483648;
	}
	n = 0 - n;
	while (n / 10 > 9)
	{
		ptr[j - 1] = n % 10 + '0';
		n = n / 10;
		j--;
	}
	ptr[j - 1] = n % 10 + '0';
	if (n / 10 != 0)
		ptr[j - 2] = n / 10 + '0';
	return (ptr);
}

static char	*pnbr(char *ptr, int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = ndigit(n);
	k = j;
	while (n / 10 > 9)
	{
		ptr[j - 1] = n % 10 + '0';
		n = n / 10;
		j--;
	}
	ptr[j - 1] = n % 10 + '0';
	if (n / 10 != 0)
		ptr[j - 2] = n / 10 + '0';
	ptr[k] = '\0';
	return (ptr);
}

static char	*znbr(char *ptr)
{
	ptr[0] = '0';
	ptr[1] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = ndigit(n);
	k = j;
	if (n == 0)
		ptr = (char *)malloc(2 * sizeof(char));
	else
		ptr = (char *)malloc((j + 1) * sizeof(char));
	if (!ptr)
		return (0);
	if (n < 0)
		ptr = nnbr(ptr, n);
	else if (n > 0)
		ptr = pnbr(ptr, n);
	else
		ptr = znbr(ptr);
	return (ptr);
}

static void	ft_do(char	*s, int	**count)
{
	**count += ft_strlen(s);
	ft_putstr_fd(s, 1);
}

static void	ft_options(char	o, void *wut, int *count)
{
	if (o == 'c')
	{
		ft_putchar_fd((char *) wut, 1);
		*count = *count + 1;
	}
	else if (o == 's')
		ft_do((char *) wut, &count);
	else if (o == 'p')
		ft_do(ft_putadd((unsigned long) wut), &count);
	else if (o == 'd' || o == 'i')
		ft_do(ft_itoa((int) wut), &count);
	else if (o == 'u')
		ft_do(ft_putunsi((unsigned long) wut), &count);
	else if (o == 'x')
		ft_do(ft_putlhexa((unsigned int) wut), &count);
	else if (o == 'X')
		ft_do(ft_putuhexa((unsigned int) wut), &count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	count;

	va_start(args, format);
	i = 0;
	count = 0;
	while(format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				ft_putchar_fd('%', 1);
				count++;
				i += 2;
				continue;
			}
			else if (format[i + 1] == 's' || format[i + 1] == 'p' || format[i + 1] == 'd' ||
					format[i + 1] == 'i' || format[i + 1] == 'u' || format[i + 1] == 'x' ||
					format[i + 1] == 'X' || format[i + 1] == 'c')
					{
				ft_options(format[i + 1], va_arg(args, void *), &count);
				i += 2;
				continue;
					}
		}
		count++;
		ft_putchar_fd(format[i++], 1);
	}
	va_end(args);
	return(count);
}

int main() {
    int a = -10;
    int xx, y;
    char    x = 'u';
    char    *c = "hrez ezfaze fa";
    char    *s = "Done ------ End";
    char    *t = NULL;
    
    xx = ft_printf("%c Hello %s %d %p", x, s, a, t);
    printf("\n\n");
    y = printf("%c Hello %s %d %p", x, s, a, t);
    printf("\n\n%d == %d", xx, y);
    return 0;
}