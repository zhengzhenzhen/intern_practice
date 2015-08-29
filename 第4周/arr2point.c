/*计算班级成绩，用二维数组指针*/

#include <stdio.h>
#define M 3
#define N 4

//float sc[M];
float avr(float *s, int n);
void score(float (*p)[N], int n);

int main(){
	int num;
	
	static float sc[4][4] = {
		{76.0, 90.0, 92.5, 87.0}, {68.0,78.0, 69.0, 94.0},
		{89.0, 82.0, 65.0, 76.0}, {78.0, 90.5, 87.5, 88.0}
		};
	printf("班级总平均分");
	printf("%5.2f\n", avr(*sc, 16));
	printf("输入学号(0-3):");
	scanf("%d", &num);
	score(sc,num);
	return 0;
}

float avr(float *s, int n){
	float *end;
	float sum = 0.0;
	end = s+n-1;
	for(; s<=end; ++s){
		sum += *s;
	}
	return sum/(float)n;
}

void score(float (*p)[N],int n){
	int j = 0;
	printf("第%d个学生成绩：\n", n);
	for(; j<N; ++j){
	//p+n指向score[n]、*(p+n)+j是score[n][j]的地址，*(*(p+n)+j)是score[n][j]的值
		printf("%5.2f ", *(*(p+n)+j));
	}
	printf("\n");
	
}
