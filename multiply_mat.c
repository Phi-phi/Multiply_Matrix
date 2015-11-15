#include <stdio.h>
#include <stdlib.h>

typedef struct matrix{
	float *mat;
	int row;
	int col;
} Mat;

void f_input(float *num, char *str){
	printf("%s", str);
	scanf("%f", num);
	printf("\n");
}

void i_input(int *num, char *str){
	printf("%s", str);
	scanf("%d", num);
	printf("\n");
}

float* loader(Mat *mat, int x, int y){
	float *addr;
	addr = &mat -> mat[mat -> row * y + x];
	return addr;
}

void fill_mat(Mat *mat){
	int i, j;
	float *point;

	for(i = 0; i < mat -> row; ++i){
		for(j = 0; j < mat -> col; ++j){
			point = loader(mat, i, j);
			printf("%d - %d\n", i + 1, j + 1);
			f_input(point, "set=>");
		}
	}
}

Mat *multiply(Mat *mat1, Mat *mat2){
	Mat *ans;
	int i, j, k;
	float box = 0;
	float *num1, *num2, *point;
	ans = (Mat*)malloc(sizeof(Mat));
	ans -> row = mat2 -> row;
	ans -> col = mat1 -> col;
	ans -> mat = (float*)malloc(sizeof(float) + ans -> row + ans -> col);
	for(i = 0; i < mat1 -> col; ++i){
		for(j = 0; j < mat2 -> row; ++j){
			box = 0;
			for(k = 0; k < mat1 -> row; ++k){
				num1 = loader(mat1, k, i);
				num2 = loader(mat2, j, k);
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
	float *point;

	printf("****MATRIX****\n");
	for(i = 0; i < mat -> col; ++i){
		for(j = 0; j < mat -> row; ++j){
			point = loader(mat, j, i);
			printf("%f   ", *point);
		}
		printf("\n");
	}

}

int main(int argc, char* argv[]){
	int i, j;
	int rows, cols;
	Mat *mat1 = (Mat*)malloc(sizeof(Mat));
	Mat *mat2 = (Mat*)malloc(sizeof(Mat));
	Mat *ans;
	float *point;

	i_input(&mat1 -> row, "ROW1=>");
	i_input(&mat1 -> col, "COLUM1=>");
	i_input(&mat2 -> row, "ROW2=>");
	i_input(&mat2 -> col, "COLUM2=>");
	mat1 -> mat = (float*)malloc(sizeof(float) * mat1 -> row * mat1 -> col);
	mat2 -> mat = (float*)malloc(sizeof(float) * mat2 -> row * mat2 -> col);

	fill_mat(mat1);
	fill_mat(mat2);

	ans = multiply(mat1, mat2);

	indicate(ans);

	return 1;
}
