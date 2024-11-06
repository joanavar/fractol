/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <joanavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:01:27 by joanavar          #+#    #+#             */
/*   Updated: 2024/05/30 22:14:54 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     close_funtion(t_fractal *fractal)
{
    if (fractal->img.img_ptr)
        mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
    if (fractal->mlx_window)
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    exit(EXIT_SUCCESS);
}

int	key_handler(int key, t_fractal *fractal)
{
    if (key == KEY_ESC)
		close_funtion(fractal);
    else if (key == KEY_UP || key == KEY_W)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (key == KEY_DOWN || key == KEY_S)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (key == KEY_RIGHT || key == KEY_D)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (key == KEY_LEFT || key == KEY_A)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (key == KEY_PLUS)
		fractal->iterations_definition += 1;
	else if (key == KEY_MINUS)
		fractal->iterations_definition -= 1;
	else if (key == KEY_Q)
		fractal->zoom *= 1.05;
	else if (key == KEY_E)
		fractal->zoom *= 0.95;
    else
        return (0);
	fractal_render(fractal);
	return (0);
}

int     mouse_handler(int button, int x, int y, t_fractal *fractal)
{
    if (button == M_DOWN)
        fractal ->zoom *= 1.05;
    else if (button == M_UP)
        fractal->zoom *= 0.95;
    fractal_render(fractal);
    return (0);
}
