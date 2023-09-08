/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:49:07 by kramjatt          #+#    #+#             */
/*   Updated: 2022/08/22 18:49:09 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (str[0] >= 'a' && str[0] <= 'z')
	{
		str[i] = str[i] - 32;
	}
	
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i - 1] == ' ')
			{
				str[i] = str[i] - 32;
			}
		}
		i++;
	}
	return (str);
}

int	main(void)
{
	char	strr[] = "+je m'appeLLe keny";
	
	printf("%s", ft_strcapitalize(strr));
	
	return (0);
}
