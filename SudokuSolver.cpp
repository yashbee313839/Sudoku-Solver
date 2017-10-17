#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define kr 9
#define kc 9
#define kv 9
#define width 3

int grid[kr][kc];

int load(const char *path) {
	FILE *file = fopen(path, "r");
	if (!file)
		return 0;
	for (int row = 0; row < kr; row++) {
		for (int col = 0; col < kc; col++) {
			fscanf(file, "%d", &grid[row][col]);
		}
	}
	fclose(file);
	return 1;
}

int valid(int row, int col, int val) {
	for (int n = 0; n < kr; n++) {
		if (grid[n][col] == val || grid[row][n] == val)
			return 0;
	}	
	int srow = (row / width) * width;
	int scol = (col / width) * width;
		for (int r = srow; r < srow + width; r++) {
		for (int c = scol; c < scol + width; c++) {
			if (grid[r][c] == val)
				return 0;
		}
	}	
	return 1;
}

int solve(int row, int col) {
	if (row == kr)
		return 1;
	
	if (grid[row][col] != 0) {
		if (col == 8)
			return solve(row + 1, 0);
		
		return solve(row, col + 1);
	}
	
	for (int val = 1; val <= kv
	; val++) {
		if (valid(row, col, val)) {
			grid[row][col] = val;
			
			if (col == 8) {
				if (solve(row + 1, 0))
					return 1;
			}
			else {
				if (solve(row, col + 1))
					return 1;
			}
		}
	}
	
	grid[row][col] = 0;
	
	return 0;
}

int main (int argc,const char *argv[]) {
	if (argc!=2) {
		printf("Usage: sudoku /path/to/puzzle.txt\n");
		return EXIT_SUCCESS;
	}
	char realPath[PATH_MAX+1];
	char *res=realpath(argv[1], realPath);
	if (!res){
		printf("Invalid\n");
		return EXIT_FAILURE;
	}
	if (!load(realPath)) {
		printf("Cant load puzzle\n");
		return EXIT_FAILURE;
	}
	if (solve(0, 0)) {
		printf("Solution:\n\n");
		for (int row = 0; row < kr; row++) {
			for (int col = 0; col < kc; col++) {
				printf("%d ", grid[row][col]);
			}
			printf("\n");
		}
	}
	else
		printf("No solution exists\n");
	return EXIT_SUCCESS;
}