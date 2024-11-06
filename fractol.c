/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <joanavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:27:30 by joanavar          #+#    #+#             */
/*   Updated: 2024/05/31 20:15:04 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void set_fractal(t_fractal *fractal)
{
    fractal_init(fractal);
    fractal_render(fractal);
    events_init(fractal);
    mlx_loop(fractal->mlx_connection);
}

int main (int argc, char **argv)
{
    t_fractal   fractal;

    if(argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
    {
        fractal.name = argv[1];
        set_fractal(&fractal); 
    }
    else if (argc == 4 && !ft_strncmp(argv[1], "julia", 6))
    {
        fractal.name = argv[1];
        fractal.julia_x = ft_dbatoi(argv[2]);
        fractal.julia_y = ft_dbatoi(argv[3]);
        set_fractal(&fractal);
    }
    
    else
    {
        ft_putstr_fd("ERROR", 1);
        exit(EXIT_FAILURE);
    }
}
