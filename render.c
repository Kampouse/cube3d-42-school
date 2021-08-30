#include "solong.h"
#include "stdio.h"
#include "utils/libft/libft.h"
#include "utils/minilibx/mlx.h"

int render_walk(screen *state);
int render_image(screen *state, int x, int y, int image) 
{
  mlx_put_image_to_window(state->mlx, state->win, state->tiles[image], x, y);
  // have to store that image somewhere othewise it will lead to leaks...
  return (0);
}

int type_render(screen *state, char type) 
{
  if (type == '1')
    return (1);
 if (type == 'C')
	 return(3);
 if (type == 'E')
	 return(2);
return (0);
}
void player_finder(screen *state, int x_axis, int y_axis) 
{
  int vert, horz;

  vert = 0;
  horz = vert;
  while (state->map[vert]) 
	{
    horz = 0;
    x_axis = 0;
    while (state->map[vert][horz]) 
		{
      x_axis += 42 ;
      if (state->map[vert][horz] == 'P') 
			{
        state->locationX = horz;
        state->locationY = vert;
        state->x_pos = x_axis;
        state->y_pos = y_axis;
      }
      horz++;
    }
    y_axis += 20;
    vert++;
  }
}
int rend_dec(screen *state)
{
	
	  if(state->moveX > 0)
	{
		state->moveX-=10;
		state->x_pos += 10;
	}
	if(state->moveX < 0)
	{
		state->moveX +=10;
		state->x_pos -=10;
	}
	if(state->moveY > 0)
	{
		state->moveY -=10;
		state->y_pos +=10;
	}
	if(state->moveY < 0)
	{
		state->moveY +=10;
		state->y_pos -=10;
	}
	return(render_walk(state));
}
int render_player(screen *state) 
{
	
	rend_dec(state);
  render_tiles(state,0, 0);
	 render_image(state, state->x_pos,  state->y_pos, state->image_state);
	 
  return (0);
}
int render_walk(screen *state)
{
	static int  image_state;
		//render_tiles(state,0, 0);
	if(state->moveX != 0)
		image_state++;
if(image_state == 9)
	image_state = 6;
  return (image_state);
}
int render_tiles(screen *state, int x_axis, int y_axis) 
{
  int inc, cin;

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
