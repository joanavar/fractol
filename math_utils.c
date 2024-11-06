/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <joanavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:13:07 by joanavar          #+#    #+#             */
/*   Updated: 2024/05/29 22:34:09 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// para pasar de (0, 799) a (-2, 2)

double map(double unscaled_num, double new_min, double new_max, double old_max)
{
    	return ((new_max - new_min) * (unscaled_num - 0) / (old_max - 0) + new_min);

}

t_complex   sum_complex(t_complex z1, t_complex z2)
{
    t_complex   result;

    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return (result);
}

/*
real = (x^2 - y^2)
i = 2*x*y
*/
t_complex   square_complex(t_complex z)
{
    t_complex   result;

    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    return (result);
}