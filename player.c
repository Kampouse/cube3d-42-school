#include "solong.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils/get_next_line.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"

void	play_contact(screen *state)
{
	if (state->map[state->locationY][state->locationX] == 'C')
	{
		state->map[state->locationY][state->locationX] = '0';
		state->collected++;
	}
	if (state->map[state->locationY][state->locationX] == 'E'
		&& state->collected == 2)
	{
		printf("won");
	}
}

void	play_right(screen *state, int keycode)
{
	if (keycode == RIGHT)
	{
		if (state->image_state >= 8 && state->image_state < 13)
		{
			state->image_state++;
		}
		else
		{
			state->image_state = 10;
		}
	}
}

void	play_left(screen *state, int keycode)
{
	if (keycode == LEFT)
	{
		if (state->image_state > 4 && state->image_state < 8)
		{
			state->image_state++;
		}
		else
		{
			state->image_state = 5;
		}
	}
}

void	play_horz(screen *state, int keycode)
	{
	play_left(state, keycode);
	play_right(state, keycode);
	if (keycode == LEFT)
	{
		if (state->map[state->locationY][state->locationX - 1] != '1')
		{
			state->moveX -= 88;
			state->locationX -= 1;
			state->moveCount++;
		}
		rend_dec(state);
		ft_putnbr_fd(state->moveCount, 1);
	}
	if (keycode == RIGHT && state->map[state->locationY]
		[state->locationX + 1] != '1')
	{
		state->moveX += 88;
		state->locationX += 1;
		state->moveCount++;
		render_player(state);
		ft_putnbr_fd(state->moveCount, 1);
	}
}

void	play_vert(screen *state, int keycode)
{
	if (keycode == UP && state->map[state->locationY - 1]
		[state->locationX] != '1')
	{
		state->locationY -= 1;
		state->moveY -= 56;
		state->moveCount++;
		render_player(state);
		ft_putnbr_fd(state->moveCount, 1);
	}
	if (keycode == DOWN && state->map[state->locationY + 1]
		[state->locationX] != '1')
	{
		state->locationY += 1;
		state->moveY += 56;
		state->moveCount++;
		render_player(state);
		ft_putnbr_fd(state->moveCount, 0);
	}
}
