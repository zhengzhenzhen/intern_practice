#include <stdio.h>

int main(){
	int a[5], b[2][3];
	int *p1, *p2, **p3;//p3是指向指针的指针变量
	int i = 0, j = 0;
	
	printf("请输入一维数组（5个整数）：\n");
	for(i=0; i<5; ++i){
		scanf("%d", &a[i]);
	}
	printf("请输入二维数组(2行3列):\n");
	for(i=0; i<2; ++i){
		for(j=0; j<3; ++j){
			scanf("%d", &b[i][j]);
		}
	}
	printf("\n");
	//分别给一维指针变量p1和二维指针变量p3赋初值
	for(p1=a, p3=&p1, i=0; i<5; ++i){
		printf("%4d", *(*p3+i));//用二维指针变量输出一维数组（方法一）
	}
	printf("\n");
	for(p1=a, p3=&p1; p1-a<5; ++p1){//用二维指针变量输出一维数组（方法二）
		//p3 = &p1;
		printf("%4d", **p3);
	}
	printf("\n");
	
	for(i=0; i<2; ++i){//用二维指针变量输出二维数组（方法一）
		p2 = b[i];
		p3 = &p2;
		for(j=0; j<3; ++j){
			printf("%4d", *(*p3+j));
		}
	printf("\n");
	}

	for(i=0; i<2; ++i){
		p2 = b[i];
		for(; p2-b[i]<3; ++p2){
			p3 = &p2;
			printf("%4d", **p3);
		}
	printf("\n");
 	}	

	return 0;
}
