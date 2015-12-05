#ifndef TOOLS_H
#define TOOLS_H

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