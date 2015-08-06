#include <stdio.h>

#define M 4
#define N 5

void averscore(float *pscore, float *paver);
void avercour5(char *pcourse, float *pscore);
void fail2(char *pcourse, int *pnum, float *pscore, float *paver);
void great(char *pcourse, int *pnum, float *pscore, float *paver);

int main(){
	int i = 0, j = 0;
	int *pnum, num[M]; //num存放每位学生的学号
	
	float score[M][N], *pscore;
	float aver[M], *paver; //aver存放每位学生的平均分
	
	char course[N][40], *pcourse; //course存放5门课程的名称

	printf("请按行输入5门功课的名称：\n");
	pcourse = course[i];
	for(i=0; i<N; ++i){
		scanf("%s", pcourse+40*i);
	}		

	printf("请按照下面的格式输入4个学生的学号和各科成绩：(以空格间隔)\n");
	printf("学号");
	for(i=0; i<N; ++i){
		printf(" %s", pcourse+40*i);
	}
	printf("\n");

	pscore = &score[0][0];
	pnum = &num[0];
	for(i=0; i<M; ++i){
		scanf("%d", pnum+i);
		for(j=0; j<N; ++j){
			scanf("%f", pscore+N*i+j);
		}
	}

	paver = &aver[0];
	printf("\n\n");
	averscore(pscore, paver); 
	avercour5(pcourse, pscore);
	printf("\n\n");
	fail2(pcourse, pnum, pscore, paver);
	printf("\n\n");
	great(pcourse, pnum, pscore, paver);
	return 0;
}


//求每个学生的平均成绩
void averscore(float *pscore, float *paver){
	int i = 0, j = 0;
	float sum = 0.0, average = 0.0;
	for(i=0; i<M; ++i){
		sum = 0.0;
		for(j=0; j<N; ++j){
			sum += (*(pscore+N*i+j));
		}
		average = sum/N;
		*(paver+i) = average;
	}
}

//求第五门课程的平均成绩
void avercour5(char *pcourse, float *pscore){
	int i = 0;
	float sum = 0.0, average5 = 0.0;
	for(i=0; i<M; ++i){
		sum += *(pscore+N*i+4);
	}
	average5 = sum/M;   
	printf("第5门课程%s的平均成绩是%5.2f\n", pcourse, average5);
}

//求两门以上成绩不及格的学生,并输出他们的学号和全部课程成绩以及平均成绩
void fail2(char *pcourse, int *pnum, float *pscore, float *paver){
	int i = 0, j = 0;
	int k = 0, flag = 0;
	printf("    =====两门以上课程不及格的学生=====    \n");
	printf(" 学号 ");
	for(i=0; i<N; ++i){
		printf(" %-8s", pcourse+40*i);  //输出课程名称
	}
	printf("  平均分\n");
	for(i=0; i<M; ++i){
		flag = 0;
		for(j=0; j<N; ++j){
			if(*(pscore+N*i+j) < 60.0){
				flag++;
			}
		}
		if(flag >= 2){
			//输出学号
			printf("%-4d", *(pnum+i));
			//输出各科成绩
			for(k=0; k<N; ++k){
				printf("    %-5.2f", *(pscore+N*i+k));
			}
			//输出该学生的平均分
			printf("    %-5.2f\n", *(paver+i));
		}
	}
}

//求出平均成绩在90分以上或者全部课程成绩在85分以上的学生
void great(char *pcourse, int *pnum, float *pscore, float *paver){
	int i = 0, j = 0;
	int k = 0, flag = 0;
	printf("    =====成绩优秀的学生=====    \n");
	printf(" 学号 ");

	for(i=0; i<N; ++i){
		printf(" %-8s", pcourse+40*i);
	}	
	printf(" 平均分\n");
	for(i=0; i<M; ++i){
		flag = 0;
		for(j=0; j<N; ++j){
			if(*(pscore+N*i+j) >= 85.0){
				flag++;
			}
		}
		if((flag>=5) || (*(paver+i)>=90)){
			printf("%-4d", *(pnum+i));
			for(k=0; k<N; ++k){
				printf("   %-5.2f", *(pscore+N*i+k));
			}	
			printf("  %-5.2f\n", *(paver+i));
		}
	}
}








































