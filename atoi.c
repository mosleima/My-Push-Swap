/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mosleima <marvin@42.fr>                    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/09/02 12:31:52 by mosleima          #+#    #+#             */
/*   Updated: 2024/09/02 12:32:47 by mosleima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	handle_sign(const char **str)
{
	int sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

int	ft_atoi_safe(const char *str, int *error)
{
	long long result;
	int sign;

	result = 0;
	*error = 0;
	sign = handle_sign(&str);
	if (*str < '0' || *str > '9')
	{
		*error = 1;
		return (0);
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			*error = 1;
			return (0);
		}
		result = result * 10 + (*str - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	return ((int)(result * sign));
}
