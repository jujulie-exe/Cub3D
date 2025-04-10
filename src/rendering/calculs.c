#include "../../include/render3d.h"

void	calc_dda(t_ray *ray, t_player *player, char **map)
{
	while (!collision(ray, player, map))
	{
		ray->delta_x += cos(player->angle);
		ray->delta_y += sin(player->angle);
	}
}

float	calc_dist(float X, float y)
{
	float	dst;

	dst = sqrt(x * x + y * y);
	return (dst);
}

float	dist_to_wall()
{
	float	dtw;


}
