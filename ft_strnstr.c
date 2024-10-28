/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:39:27 by ehamza            #+#    #+#             */
/*   Updated: 2024/10/28 21:42:52 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;

	i = 0;
	len_little = ft_strlen(little);
	if (!little)
		return ((char *)big);
	while (*big && i < len)
	{
		if (ft_strncmp(big, little, len_little) == 0 && i + len_little <= len)
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main()
// {
// 	char big[] = "code with hippo";
// 	char little[] = "h ";
// 	char *res = ft_strnstr(big, little, 20);
// 	if (res == 0)
// 	{
// 		printf("ghskca");
// 	}
// 	printf("%s\n", res);
// }
