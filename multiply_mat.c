#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "matrix.h"

int main(int argc, char* argv[]){
	int i, j;
	int row1, row2, col1, col2;
	Mat *mat1, *mat2, *ans;
	double *point;

	i_input(&row1, "ROW1=>");
	i_input(&col1, "COLUMN1=>");
	i_input(&row2, "ROW2=>");
	i_input(&col2, "COLUMN2=>");
	mat1 = mat_initialize(row1, col1);
	mat2 = mat_initialize(row2, col2);

	fill_mat(mat1);
	fill_mat(mat2);

	printf("1st Matrix\n");
	indicate(mat1);
	printf("2nd Matrix\n");
	indicate(mat2);

	ans = multiply(mat1, mat2);

	indicate(ans);

	free(mat1);
	free(mat2);
	free(ans);

	return 1;
}
