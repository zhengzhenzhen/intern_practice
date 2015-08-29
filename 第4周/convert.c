/*将一个二维数组（矩阵）转置*/

#include <stdio.h>
#include <stdlib.h>
#define N 3

void convert(int element[N][N]);

int main(/*int argc, char *argv[]*/){
	int i = 0, j = 0;
	int array[N][N];
/*	int array[N][N] = {};
	for(i=1; i<10; ++i){
		array[N][N] = atoi(argv[1]);	
	}
*/

	printf("请输入数组元素(三行三列的整数)：\n");
	for(i=0; i<N; ++i){
		for(j=0; j<N; ++j){
			scanf("%d", &array[i][j]);
		}
	}

	printf("矩阵为：\n");
	for(i=0; i<N; ++i){
		for(j=0; j<N; ++j){
			printf("%5d", array[i][j]);
			//printf("\n");
		}
		printf("\n");
	}
	convert(array);
	printf("矩阵置换后为：\n");
	for(i=0; i<N; ++i){
                for(j=0; j<N; ++j){
                        printf("%5d", array[i][j]);
			//printf("\n");
                }
		printf("\n");
        }
	return 0;
}

void convert(int element[N][N]){
	int i = 0, j = 0;
 	int temp = 0;
	for(i=0; i<N; ++i){
		for(j=i+1; j<N; ++j){
			temp = element[i][j];
			element[i][j] = element[j][i];
			element[j][i] = temp;
		}
	}
}
