#include "sandpiles.h"

/**
 * sandpiles_sum - sum each position of each grid
 *@grid1: first grid
 *@grid2: second grid
 *Return: nothing
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int cell_1 = 0;
	int cell_2 = 0;

	for (cell_1 = 0; cell_1 < 3; cell_1++)
	{
		for (cell_2 = 0; cell_2 < 3; cell_2++)
		{
			grid1[cell_1][cell_2] = grid1[cell_1][cell_2] + grid2[cell_1][cell_2];
		}
	}
	analyze_table(grid1);
}

/**
 * print_to_output - prints the grid
 *@grid: the grid
 * Return: nothing
*/
void print_to_output(int grid[3][3])
{
	int idx_1 = 0;
	int idx_2 = 0;

	printf("=\n");

	for (idx_1 = 0; idx_1 < 3; idx_1++)
	{
		for (idx_2 = 0; idx_2 < 3; idx_2++)
		{
			if (idx_2)
			{
				printf(" ");
			}
			printf("%d", grid[idx_1][idx_2]);
		}
		printf("\n");
	}
}

/**
 * t_top_sand - transform topple_to_sand
 *@grid: grid to review
 * Return: nothing
 */

void t_top_sand(int grid[3][3])
{
	int grid2[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	int cell_1 = 0;
	int cell_2 = 0;
	int tmp_n = 0;


	for (cell_1 = 0; cell_1 < 3; cell_1++)
	{
		for (cell_2 = 0; cell_2 < 3; cell_2++)
		{
			tmp_n = grid[cell_1][cell_2];
			if (tmp_n > 3)
			{
				grid[cell_1][cell_2] = tmp_n - 4;
				if (cell_1 + 1 < 3)
					grid2[cell_1 + 1][cell_2]++;
				if (cell_1 - 1 >= 0)
					grid2[cell_1 - 1][cell_2]++;
				if (cell_2 + 1 < 3)
					grid2[cell_1][cell_2 + 1]++;
				if (cell_2 - 1 >= 0)
					grid2[cell_1][cell_2 - 1]++;
			}
		}
	}
	sandpiles_sum(grid, grid2);
}

/**
 * analyze_table - evaluate if the grid is stable
 *@grid: grid to evaluate
 * Return: nothing
 */
void analyze_table(int grid[3][3])
{
	int cell_1 = 0;
	int cell_2 = 0;
	int tmp_n = 0;
	int conf = 0;

	for (cell_1 = 0; cell_1 < 3; cell_1++)
	{
		for (cell_2 = 0; cell_2 < 3; cell_2++)
		{
			tmp_n = grid[cell_1][cell_2];
			if (tmp_n > 3)
			{
				conf = 1;
				break;
			}
		}
	}
	if (conf == 1)
	{
		print_to_output(grid);
		t_top_sand(grid);
	}
}
