/*验证哥德巴赫猜想*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	//
	int  num = 0;
        int  p = 0, q = 0, i = 0, j = 0;
	num = atoi(argv[1]);
	printf("num=%d\n",num);
	int flagp = 0, flagq = 0; //判断p和q是否为素数的标志
	//
/*	scanf("%d", &num);
	while(num <= 2 || num%2 != 0){
		printf("输入错误，请重新输入一个大于2的整数：");
		scanf("%d", &num);
	}
*/
	//判断p是否为素数
	p = 1;
	do{
		++p;
		q = num - p;
		flagp = 1;
		flagq = 1;
		for(i = 2; i <= (int)(floor(sqrt(p))); ++i){
			if(p%i == 0){
				flagp = 0;
				break;	
			}
		}
		for(j = 2; j <= (int)(floor(sqrt(q))); ++j){
			if(q%j == 0){
				flagq = 0;
				break;
			}
		}
	}while(flagp*flagq == 0);
	printf("%d = %d + %d\n", num, p, q);
	return 0;
}
