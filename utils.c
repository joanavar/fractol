/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <joanavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:08:29 by joanavar          #+#    #+#             */
/*   Updated: 2024/05/31 19:55:51 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
        return(0);
    while (*s1 == *s2 && n > 0 && *s1 != '\0')
    {
        s1++;
        s2++;
        n--;
    }
    return (*s1 - *s2);
}

void	ft_putstr_fd(char *s, int fd)
{
    if (s == NULL || fd < 0)
        return ;
    int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

#include<stdio.h>

static double   help_dbatoi(char *str)
{
    long    number;
    double  decimal;
    double  dec;

    number = 0;
    decimal = 0;
    dec = 1;
    while (*str != '.' && *str)
    {
        number = (number * 10) + (*str - '0');
        str++;
    }
    if (*str == '.')
        str++;
    while (*str)
    {
        dec /= 10;
        decimal = decimal + (*str - '0') * dec;
        str++;
    }
    return (number + decimal);
}

double  ft_dbatoi(char *str)
{
    printf("aqui\n");
    int     sign;
    double  nbr;

    sign = 1;
    nbr = 0;
    while ((*str >= '\t' && *str <= '\r') || *str == ' ')
        str++;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign *= -1;
        str++;
    }
    nbr = help_dbatoi(str);
    return (nbr * sign);
}



