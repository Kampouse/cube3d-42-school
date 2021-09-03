#include "solong.h"
#include "stdio.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"

int	render_walk(screen *state);

int	render_image(screen *state, int x, int y, int image)
{
	mlx_put_image_to_window(state->mlx, state->win, state->tiles[image], x, y);
	return (0);
}

int	rend_dec(screen *state)
{
	  if (state->moveX > 0)
	{
		state->moveX -= 10;
		state->x_pos += 10;
	}
	if (state->moveX < 0)
	{
		state->moveX += 10;
		state->x_pos -= 10;
	}
	if (state->moveY > 0)
	{
		state->moveY -= 10;
		state->y_pos += 10;
	}
	if (state->moveY < 0)
	{
		state->moveY += 10;
		state->y_pos -= 10;
	}
	return (render_walk(state));
}

int	render_player(screen *state)
{
	rend_dec(state);
	render_tiles(state, 0, 0);
	render_image(state, state->x_pos, state->y_pos, state->image_state);
	return (0);
}

int	render_walk(screen *state)
{
	static int	image_state;

	if (state->moveX != 0)
		image_state++;
	if (image_state == 9)
		image_state = 6;
	return (image_state);
}

int	render_tiles(screen *state, int x_axis, int y_axis)
{
	int	inc;
	int	cin;

	inc = 0;
	cin = 0;
	while (state->map[inc])
	{
		cin = 0;
		x_axis = 0;
		while (state->map[inc][cin])
		{
			render_image(state, x_axis, y_axis,
				type_render(state, state->map[inc][cin]));
			x_axis += 89;
			cin++;
		}
		y_axis += 56;
		inc++;
	}
	return (0);
}
