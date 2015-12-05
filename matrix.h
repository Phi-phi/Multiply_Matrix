#ifndef MATRIX_H
#define MATRIX_H

#include "tools.h"

typedef struct matrix{
	double *nums;	//numbers in matrix
	int cols;		//cols
	int row;		//rowumn
} Mat;

double* loader(Mat *mat, int x, int y){		//return address at specified coordinates in the matrix.
	double *addr;
	addr = &(mat->nums[(mat->cols) * y + x]); // address of data whose cols is x, and rowumn is y.
	return addr;
}

Mat *mat_initialize(int cols, int row){		//initialize Matrix's struct.
	Mat *mat = (Mat*)malloc(sizeof(Mat));
	mat->cols = cols;
	mat->row = row;
	mat->nums = (double*)malloc(sizeof(double) * cols * row); //putting matrix's data as 1d.

	return mat;
}

void fill_mat(Mat *mat){				//filling matrix.
	int i, j;
	double *point;

	for(i = 0; i < (mat->cols); ++i){
		for(j = 0; j < (mat->row); ++j){
			point = loader(mat, i, j);
			printf("%d - %d\n", i + 1, j + 1);
			f_input(point, "set=>");
		}
	}
}

Mat *multiply(Mat *mat1, Mat *mat2){
	Mat *ans = mat_initialize(mat2->cols, mat1->row);
	int i, j, k;
	double box;
	double *num1, *num2, *point;

	for(i = 0; i < (mat1->row); ++i){
		for(j = 0; j < (mat2->cols); ++j){
			box = 0;				//box is for putting one part in matrix of answer temporarily.
			for(k = 0; k < (mat1->cols); ++k){
				num1 = loader(mat1, k, i);
				num2 = loader(mat2, j, k);	//load two addresses of numbers to multiply.
				box += (*num1) * (*num2);
			}
			point = loader(ans, j, i);
			*point = box;
		}
	}
	return ans;
}

void indicate(Mat *mat){
	int i, j;
	double *point;

	printf("****MATRIX****\n");
	for(i = 0; i < (mat->row); ++i){
		for(j = 0; j < (mat->cols); ++j){
			point = loader(mat, j, i);
			printf("%12f   ", *point);
		}
		printf("\n");
	}
}

#endif
