#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	long long int map[40][40];
	for (int i = 1, j = 1; i < 40; i++) {
		for (; j < 40; j++)
			map[i][j] = 1;
	}
	long long int bx, by, mx, my, ret;
	scanf("%lld%lld%lld%lld", &bx, &by, &mx, &my);
	mx += 2;
	my += 2;
	bx += 2;
	by += 2;
	map[mx][my] = 0;
	map[mx + 2][my + 1] = 0;
	map[mx + 2][my - 1] = 0;
	map[mx - 2][my + 1] = 0;
	map[mx - 2][my - 1] = 0;
	map[mx + 1][my + 2] = 0;
	map[mx + 1][my - 2] = 0;
	map[mx - 1][my + 2] = 0;
	map[mx - 1][my - 2] = 0;
	map[bx][by] = 3;
	for (int i = 1, j = 1; i < 40; i++)
		map[i][j] = 0;
	for (int i = 1, j = 1; j < 40; j++)
		map[i][j] = 0;
	map[2][1] = 1;
	map[2][2] = 1;
	for (int i = 2; i <= bx; i++) {
		for (int j = 2; j <= by; j++) {
			if (map[i][j] == 0) continue;
			map[i][j] = map[i - 1][j] + map[i][j - 1];
		}
	}
	printf("%lld", map[bx][by]);
	return 0;
}
/*
long long int map[40][40] = {0};
long long int Move( int bx, int by)
{
	if (map[bx - 1][by] == 0 && map[bx][by - 1] == 0)
		return Move(bx - 1, by) + Move(bx, by - 1);
	else if (map[bx - 1][by] == -1 && map[bx][by - 1] == 0)
		return Move(bx, by - 1);
	else if (map[bx][by - 1] == -1 && map[bx - 1][by] == 0)
		return Move(bx - 1, by);
	else if (map[bx - 1][by] == 3 || map[bx][by - 1] == 3)
		return 1;
	else if (map[bx - 1][by] == -1 && map[bx][by - 1] == -1)
		return 0;
}
int main()
{
	map[2][2] = 3;
	long long int bx, by, mx, my, ret;
	scanf("%lld%lld%lld%lld", &bx, &by, &mx, &my);
	mx += 2, my += 2;
	map[mx][my] = -1;
	map[mx + 2][my + 1] = -1;
	map[mx + 2][my - 1] = -1;
	map[mx - 2][my + 1] = -1;
	map[mx - 2][my - 1] = -1;
	map[mx + 1][my + 2] = -1;
	map[mx + 1][my - 2] = -1;
	map[mx - 1][my + 2] = -1;
	map[mx - 1][my - 2] = -1;
	map[bx+2][by+2] = 3;
	for (int i = 1, j = 1; i <40; i++)
		map[i][j] = -1;
	for (int i = 1, j = 1; j <40; j++)
		map[i][j] = -1;
	ret = Move(bx + 2, by + 2);
	printf("%lld", ret);
	return 0;
}*/


