/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:00:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/05/16 13:45:25 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cube.h"

float	distance(ax, ay, bx, by, ang)
{
	return (cos(ang)*(bx-ax)-sin(ang)*(by-ay));
}

int	raycaster2d(t_game *game, t_image image)
{
	t_ray	ray;
	int		inc;
	int		stepx;
	int		stepy;
	float	stepsize_x;
	float	stepsize_y;
	
	inc = 0;
	ray.angle = game->player->direction;
	ray.delta_y = cos(ray.angle) / 1;
	ray.delta_x = sin(ray.angle);
	ray.dx = cos(degToRad(ray.angle)) * ray.delta_x -  sin(degToRad(ray.angle)) * ray.delta_y;
	ray.dy = sin(degToRad(ray.angle)) * ray.delta_x + cos(degToRad(ray.angle)) * ray.delta_y;
	ray.max_value = fmax(fabs(ray.dx), fabs(ray.dy));
	ray.dx /= ray.max_value;
	ray.dy /= ray.max_value;
	// En dessous, on itere sur chaque scaling point jusquau prochain mur au lieu de calculer
	// Des points sans passer sur tous.
	while(game->map[(int)(game->player->y_pos + (ray.dy * inc)) / game->player->scale][(int)(game->player->x_pos + (ray.dx * inc))  / game->player->scale] != '1')
		inc += 1;
	printf("delta_x = %f\ndelta_y = %f\ndx = %f\ndy = %f\n", ray.delta_x, ray.delta_y, ray.dx, ray.dy);
	stepsize_y = sqrt(1 + (ray.dy / ray.dx) * (ray.dy / ray.dx));
	stepsize_x = sqrt(1 + (ray.dx / ray.dy) * (ray.dx / ray.dy));
	printf("stepsize_x = %f\nstepsize_y = %f\n\n\n", stepsize_x, stepsize_y);
	stepx = game->player->x_map;
	stepy = game->player->y_map;
	if (ray.dx < 0)
		stepx = -1;
	else
		stepx = 1;
	if (ray.dy < 0)
		stepy = -1;
	else
		stepy = 1;
	draw_line(&image, game->player->x_pos, game->player->y_pos, game->player->x_pos + (ray.dx * inc), game->player->y_pos + (ray.dy * inc));
	return (0);
}

int	ray_fov(t_game *state, t_image image , float angle, int inc)
{
	float	until;
	float	plus;
	(void)angle;
	(void)inc;

	plus = 0;
	until = state->player->direction + PI / 3;
	raycaster2d(state, image);
	// while(state->player->direction + plus < until)
	// {
	// 	ray.angle = state->player->direction + plus;
	// 	raycaster2d(state, image, ray);
	// 	ray.angle = state->player->direction - plus;
	// 	raycaster2d(state, image, ray);
	// 	plus += PI / 84; 
	// }
	return (0);
}

/*
int raycaster3d(t_game *game, t_image image, t_ray ray,int scree_strip)
{
	int inc;
	inc = 0;
	ray.delta_y = cos(ray.angle) / 1;
	ray.delta_x = sin(ray.angle);
	ray.dx = cos(degToRad(ray.angle)) * ray.delta_x -  sin(degToRad(ray.angle)) * ray.delta_y;
	ray.dy = sin(degToRad(ray.angle)) * ray.delta_x + cos(degToRad(ray.angle)) * ray.delta_y;
	ray.max_value = fmax(fabs(ray.dx), fabs(ray.dy));
	ray.dx/= ray.max_value;
	ray.dy/= ray.max_value;
	while(game->map[ (int)(game->player->y_pos + (ray.dy * inc)) / game->player->scale][(int)(game->player->x_pos + (ray.dx * inc))  / game->player->scale] != '1')
		inc +=1;		


	float wall_height  = 21000 / ( inc + 0.001);
		printf("%f\n",wall_height);
	draw_line(&image, scree_strip,  (1080 / 2)  - wall_height / 2, scree_strip,wall_height);

	return(0);
}

int ray_fov3d(t_game *state,t_image image ,float angle,int inc)
{
	float	until;
	float	plus;
	int	scree_strip;
	t_ray	ray;
	int step = 0;
		plus = 0;
		until = state->player->direction +  PI / 3;
		while(state->player->direction + plus < until)
	{
			ray.angle = state->player->direction + plus;
					raycaster3d(state, image, ray, step);
					step+= 16;
			plus += PI  / 84;
	}
}
*/
