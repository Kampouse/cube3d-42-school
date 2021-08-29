#include "solong.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils/get_next_line.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"
 

void play_contact(screen *state)
{
if (state->map[state->locationY][state->locationX] == 'C') 
	{
 state->map[state->locationY][state->locationX] = '0';
 state->collected++;
	}

if (state->map[state->locationY][state->locationX] == 'E' && state->collected == 2) 
	{
			printf("won");
	}
}

void play_horz(screen *state, int keycode)
  {
    if (keycode == 0 &&
        state->map[state->locationY][state->locationX - 1] != '1') 
	{
      state->moveX-=88;
      state->locationX -= 1;
	  state->moveCount++;
	  render_player(state);
	  ft_putnbr_fd(state->moveCount,1);
    }  
    if (keycode == 17 &&
        state->map[state->locationY][state->locationX + 1] != '1') 
	{
      state->moveX+=88;
      state->locationX += 1;
	  state->moveCount++;
	  render_player(state);
	  ft_putnbr_fd(state->moveCount,1);
    }
}

void play_vert(screen *state, int keycode)
  {
    if (keycode == 1 &&
        state->map[state->locationY - 1][state->locationX] != '1') 
	{
      state->locationY -=1 ;
      state->moveY-=60;
	  state->moveCount++;
	  render_player(state);
	  ft_putnbr_fd(state->moveCount,1);
    }  
	if (keycode == 4 &&
        state->map[state->locationY + 1][state->locationX] != '1') 
	{
      state->locationY += 1;
      state->moveY+= 60;
	  state->moveCount++;
	  render_player(state);
	  ft_putnbr_fd(state->moveCount,0);
    }
}
