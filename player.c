#include "solong.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils/get_next_line.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"

void play_horz(screen *state, int keycode)
  {
    if (keycode == 0 &&
        state->map[state->locationY][state->locationX - 1] != '1') 
	{
      state->moveX-=70;
      state->locationX -= 1;
	  render_player(state);
    }  
    if (keycode == 17 &&
        state->map[state->locationY][state->locationX + 1] != '1') 
	{
      state->moveX+=70;
      state->locationX += 1;
	  render_player(state);
    }
}
  
void play_vert(screen *state, int keycode)
  {
    if (keycode == 1 &&
        state->map[state->locationY - 1][state->locationX] != '1') 
	{
      state->locationY -=1 ;
      state->y_pos-= 65;
	  render_player(state);
    }  
	if (keycode == 4 &&
        state->map[state->locationY + 1][state->locationX] != '1') 
	{
      state->locationY += 1;
      state->y_pos+= 65;
	  render_player(state);
    }
}
