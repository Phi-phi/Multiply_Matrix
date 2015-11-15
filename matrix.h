#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix{
	double *nums;	//numbers in matrix
	int row;		//row
	int col;		//column
} Mat;

void f_input(double *num, char *str){
	printf("%s", str);
	scanf("%10lf", num);
	printf("\n");
}

void i_input(int *num, char *str){
	printf("%s", str);
	scanf("%d", num);
	printf("\n");
}

double* loader(Mat *mat, int x, int y){		//return address at specified coordinates in the matrix.
	double *addr;
	addr = &(mat->nums[(mat->row) * y + x]); // address of data whose row is x, and column is y.
	return addr;
}

Mat *mat_initialize(int row, int col){		//initialize Matrix's struct.
	Mat *mat = (Mat*)malloc(sizeof(Mat));
	mat->row = row;
	mat->col = col;
	mat->nums = (double*)malloc(sizeof(double) * row * col); //putting matrix's data as 1d.

	return mat;
}

void fill_mat(Mat *mat){				//filling matrix.
	int i, j;
	double *point;

	for(i = 0; i < (mat->row); ++i){
		for(j = 0; j < (mat->col); ++j){
			point = loader(mat, i, j);
			printf("%d - %d\n", i + 1, j + 1);
			f_input(point, "set=>");
		}
	}
}

Mat *multiply(Mat *mat1, Mat *mat2){
	Mat *ans = mat_initialize(mat2->row, mat1->col);
	int i, j, k;
	double box;
	double *num1, *num2, *point;

	for(i = 0; i < (mat1->col); ++i){
		for(j = 0; j < (mat2->row); ++j){
			box = 0;				//box is for putting one part in matrix of answer temporarily.
			for(k = 0; k < (mat1->row); ++k){
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
	for(i = 0; i < (mat->col); ++i){
		for(j = 0; j < (mat->row); ++j){
			point = loader(mat, j, i);
			printf("%12f   ", *point);
		}
		printf("\n");
	}
}

#endif
