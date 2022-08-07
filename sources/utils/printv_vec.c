
#include "../../headers/minirt.h"

void	print_vec(t_vec vec)
{
	printf("(%f, %f, %f)\n", vec.x, vec.y, vec.z);
}

void	print_matrix(float m[3][3])
{
	printf("|%f, %f, %f|\n", m[0][0], m[0][1], m[0][2]);
	printf("|%f, %f, %f|\n", m[1][0], m[1][1], m[1][2]);
	printf("|%f, %f, %f|\n", m[2][0], m[2][1], m[2][2]);
}
