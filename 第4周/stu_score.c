/*统计学生成绩：求平均分、求平均分的方差等等*/

#include <stdio.h>
#define M 4 
#define N 3

float score[M][N];//input_stu()函数给它初值
float a_stu[N], a_course[M];//这个是全局变量，求得的值main函数要用到。

void input_stu();
void average_stu();
void average_course();
float highest(int *stu, int *cor);
float average_diff();

int main(){
	int i = 0, j = 0;
	float h = 0.0;
	int stu = 0, cor = 1;
	printf("请输入4个学生3门课程：\n");
	input_stu();
	average_stu();
	average_course();

	printf("序号  课程1  课程2  课程3  平均分\n");
	for(i=1; i<=M; ++i){
		printf("学号%d  ", i);
		for(j=1; j<=N; ++j){
			printf("%5.2f  ", score[i][j]);
		}
		printf("%5.2f", a_stu[i]);
		printf("\n");
	}
	
	for(j=1; j<=N; ++j){
		printf("课程%d的平均分是：%5.2f\n", j, a_course[j]);
	}
	
	h = highest(&stu, &cor);
	printf("最高分%5.2f是学号%d的课程%d\n", h, stu, cor);
	printf("方差是%5.2f\n", average_diff());;
	return 0;
}

void input_stu(){
	int i = 0, j = 0;
	for(i=1; i<=M; ++i){
		printf("请输入学生%d的3门成绩：\n", i);
		for(j=1; j<=N; ++j){
			scanf("%f", &score[i][j]);
		}
	}
}
//每个学生的平均分
void average_stu(){
	int i = 0, j = 0;
	int sum;
	//int sum = 0;
	for(i=1; i<=M; ++i){
		sum = 0;
		for(j=1; j<=N; ++j){
			sum += score[i][j];
		}
		a_stu[i] = sum/(float)N;
	}
}
//求每门功课的平均分
void average_course(){
	int i = 0, j = 0;
	int sum;
	//int sum = 0;
	for(j=1; j<=N; ++j){
		sum = 0;
		for(i=1; i<=M; ++i){
			sum += score[i][j];
		}
		a_course[j] = sum/(float)M;
	}
}
//找出最高分所对应的学生和课程
float highest(int *stu, int *cor){
	int i = 0, j = 0;
	float max = 0.0;
	int temp = 0;
	max = score[1][1];
	for(i=1; i<=M; ++i){
		for(j=1; j<=N; ++j){
			if(score[i][j] > max){
				temp = max;
				max = score[i][j];
				score[i][j] = temp;
				*stu = i;
				*cor = j;			
			}
		}
	}
	return max;
}
//求平均分方差
float average_diff(){
	int i = 0;
	float diff = 0.0;
	//float sx = 0, sy = 0;
	float sumx = 0.0, sumy = 0.0;
	
	for(i=1; i<=M; ++i){
		sumx += a_stu[i]*a_stu[i];
		sumy += a_stu[i];
	}
	diff = sumx/(float)M - (sumy/(float)M)*(sumy/(float)M);
	return diff;
}




