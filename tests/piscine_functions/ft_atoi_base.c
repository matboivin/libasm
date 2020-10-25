/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:21:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/25 20:41:00 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	ft_isspace(int c)
{
	return ((c == ' ') || (c == '\f') || (c == '\t') \
		|| (c == '\v') || (c == '\n') || (c == '\r'));
}

static int		conv_val(int c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

static int		ft_isbase(int c, int base)
{
	const char	*lower_hex = "0123456789abcdef";
	const char	*upper_hex = "0123456789ABCDEF";
	int			i;

	i = 0;
	while (i < base)
	{
		if ((lower_hex[i] == c) || (upper_hex[i] == c))
			return (1);
		i++;
	}
	return (0);
}

static int		ft_atoi_base(const char *str, int str_base)
{
	int			result;
	int			sign;

	if (base < 2 || base > 16)
		return (0);
	result = 0;
	sign = 1;
	while (*s && ft_isspace(*s))
		s++;
	if (*s == '-')
		sign = -1;
	if ((*s == '+') || (*s == '-'))
		s++;
	while (*s && ft_isbase(*s, base))
		result = (result * base) + conv_val(*(s++));
	return (sign * result);
}

int		main(void)
{
	printf("%d\n", ft_atoi_base("42", 2));
	printf("%d\n", ft_atoi_base("42", 8));
	printf("%d\n", ft_atoi_base("42", 10));
	printf("%d\n", ft_atoi_base("42", 16));
	return (0);
}
