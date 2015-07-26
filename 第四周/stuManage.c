#include <stdio.h>
#include <stdlib.h>
#define TRUE 1


int main(){
	int i = 0, j = 0;
	int select = 0;
	int score[5][7] = {};
	int sum = 0;
	
	//录入成绩
	printf("请输入成绩：(4行6列)\n");
	for(i=1; i<5; ++i){
		for(j=1; j<7; ++j){
			scanf("%d", &score[i][j]);
		}
	}

	do{
		printf("1、根据学号查询学生成绩\n");
		printf("2、根据考试号统计成绩\n");
		printf("3、根据考试号和学号查询成绩\n");
		printf("0、退出\n");
		printf("请输入选择（0-3）：\n");
		scanf("%d", &select);

		switch(select){
			case 0:
				printf("OK\n");
				exit(0);
				break;
			case 1:
				printf("请输入学号：");
				scanf("%d", &i);
				for(j=1; j<7; ++j ){
					printf("第%d次考试成绩为%d\n", j, score[i][j]);
					sum += score[i][j];
				}
				printf("平均成绩为%d\n", sum/6 );
				break;
			case 2:
				printf("请输入考试号：");
				scanf("%d", &j);
				for(i=1; i<5; ++i){
					printf("学号%d的学生成绩为%d\n", i, score[i][j]);
					sum += score[i][j];
				}
				printf("平均分为%d\n", sum/4);
				break;
			case 3:
				printf("请输入学号和考试号（以逗号隔开）：");
				scanf("%d,%d", &i, &j);
				printf("学号%d，考试号%d的考生成绩为%d\n", i, j, score[i][j]);
				break;
			default:
				break;
		}

	}while(TRUE);
	
	return 0;
}
