#include "../../include/cube3d.h"
#include "../../include/test_render.h"


#include <math.h>

void calc_dda(t_ray *ray, t_player *player, char **map, float ray_angle)
{
	while (!collision(ray, player, map))
	{
		ray->var_x += cos(ray_angle);
		ray->var_y += sin(ray_angle);
	}
}

float	calc_dist(float x, float y)
{
	float	dst;

	dst = sqrtf(x * x + y * y);
	return (dst);
}

void calc_height(t_mlx *mlx, t_ray *ray, t_player *player, float ray_angle)
{
	ray->dtw = dist_to_wall(player, ray, ray_angle);
	ray->height = (2.5 / ray->dtw) * (mlx->width / 2);
	ray->center_line = (mlx->height - ray->height) / 2;
	ray->last_line = ray->center_line + ray->height;
}

float dist_to_wall(t_player *player, t_ray *ray, float ray_angle)
{
	float dtw;
	float delta_x;
	float delta_y;
	float a;
	delta_x = ray->var_x - player->posx;
	delta_y = ray->var_y - player->posy;
	a = atan2(delta_y, delta_x) - ray_angle;
	dtw = calc_dist(delta_x, delta_y) * cos(a);
	return (dtw);
}
