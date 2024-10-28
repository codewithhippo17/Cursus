/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:20:11 by ehamza            #+#    #+#             */
/*   Updated: 2024/10/25 18:21:53 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	while (len != 0)
	{
		ret[i] = s[start];
		i++;
		start++;
		len--;
	}
	ret[i] = 0;
	return (ret);
}

// #include <stdio.h>

// int main()
// {
//     char str[] = "code code with hippo";
//     printf("%s\n", ft_substr(str, 0, 15));
//     return 0;
// }
