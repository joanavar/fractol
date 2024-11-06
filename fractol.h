/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <joanavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:19:27 by joanavar          #+#    #+#             */
/*   Updated: 2024/06/15 15:06:06 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "Libreries/minilibx/mlx.h"


//COMPLEX value
typedef struct  s_complex
{
    //      real
    double  x;
    //      i
    double  y;

}               t_complex;

//IMAGE
typedef struct  s_image
{
    void    *img_ptr; //pointer to image struct
    char    *pixels_ptr; //points to the actual pixels
    int     bpp; // bits por pixels
    int     endian;
    int     line_len;
}               t_img;


#define WIDTH	800
#define HEIGHT	800

/*
 *COLORS
 */

#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red

/*
 *  KEYBOARS 
*/

#define ESC = KEY_ESC=65307
#define W = KEY_W=119
#define A = KEY_A=97
#define S = KEY_S=115
#define D = KEY_D=100
#define UP = KEY_UP=65362
#define DOWN = KEY_DOWN=65364
#define LEFT = KEY_LEFT=65361
#define RIGHT = KEY_RIGHT=65363
#define R = KEY_R=114
#define Q = KEY_Q=113

/*
 * MOUSE  
*/

#define C_RIGHT 1
#define C_LEFT 2
#define C_CENTER 3
#define M_UP 5
#define M_DOWN 4


//ID FRACTAL
typedef struct s_fractal
{
    char    *name;
    //MLX
    void    *mlx_connection;//mlx_init()
    void    *mlx_window;    //mlx_new_window()
    //Image
    t_img   img;
    double  escape_value; //hypotenuse
    int     iterations_definition; // value tight  with the image quality
    double  shift_x;
    double  shift_y;
    double  zoom;
    double  julia_x;
    double  julia_y;

}               t_fractal;



//rende.c
void    fractal_render(t_fractal *fractal);



//utils.c
int	ft_strncmp(const char *s1, const char *s2, int n);
void	ft_putstr_fd(char *s, int fd);

//init.c
void    fractal_init(t_fractal *fractal);
void    data_init(t_fractal *fractal);
double  ft_dbatoi(char *str);


//maths_utils.c
double      map(double unscaled_num, double new_min, double new_max, double old_max);
t_complex   sum_complex(t_complex z1, t_complex z2);
t_complex   square_complex(t_complex z);

//events.c
int     close_funtion(t_fractal *fractal);
int	key_handler(int key, t_fractal *fractal);
int     mouse_handler(int button, int x, int y, t_fractal *fractal);
void    events_init(t_fractal *fractal);



#endif
