/*求两个正整数的最大公约数和最小公倍数*/

#include <stdio.h>

int main(){
	int num1 = 0, num2 = 0, temp = 0, x = 0, y = 0;
	printf("请输入两个正整数(以逗号隔开)：");
	scanf("%d,%d", &num1, &num2);
	//
	while(num1 <= 0 || num2 <= 0){
		printf("输入错误，请重新输入两个正整数(以逗号隔开)：");
		scanf("%d,%d", &num1, &num2);
	}
	//
	if(num2 > num1){
		temp = num2;
		num2 = num1;
		num1 = temp;
	}
	//
	x = num1; 
	y = num2;
	while(y != 0){//辗转相除法
		temp = x % y; 
		x = y;
		y = temp;	
	}
	printf("它们的最大公约数是：%d\n", x);
	printf("它们的最小公倍数是：%d\n", num1*num2/x);
	return 0;
}
