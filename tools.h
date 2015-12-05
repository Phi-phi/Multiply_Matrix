#ifndef TOOLS_H
#define TOOLS_H

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

#endif
