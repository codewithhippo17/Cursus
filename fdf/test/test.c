#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int	is_dec(char *big, int idx)
{
	int	i;
	
	i = 0;
	while (i < idx)
	{
		if (isdigit(big[i]))
			i++;
		else if (big[i] == '-' || big[i] == '+')
			i++;
		else
			return (0);
	}
	return (1);
}

int is_hex(char *big)
{
	int i;

	i = 3;
	if (strlen(big) > 9)
		return (0);
	while (big[i])
	{
		if (isdigit(big[i]))
			i++;
		else if (big[i] >= 'a' && big[i] <= 'f')
			i++;
		else if (big[i] >= 'A' && big[i] <= 'F')
			i++;
		else
			return (0);
	}
	return (1);
}
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;

	i = 0;
	len_little = strlen(little);
	if (len_little == 0)
		return ((char *)big);
	if (len < len_little)
		return (NULL);
	while (*big && i + len_little <= len)
	{
		if (strncmp(big, little, len_little) == 0)
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}

int ft_strlenz(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ',')
	{
		i++;
	}
	return (i);
}

int v_point(char *big)
{
	char *little;

	little = ft_strnstr(big, ",0x", strlen(big));
	if (!little && is_dec(big, strlen(big)))
	{
		return (1);
	}
	else if (is_dec(big, ft_strlenz(big)) && is_hex(little))
	{
		return (1);
	}
	return(0);
}

int main()
{
	printf("%d\n", v_point("012253565x365353,0xfffa"));
}