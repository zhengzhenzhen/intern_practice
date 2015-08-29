/*打印一个魔方阵*/
#include <stdio.h>

int main(){
	int num = 0;
	int array[16][16];
	//int flag = 1;
	int i = 0, j = 0, n = 0;

	while(1){
		printf("请输入一个正奇数n（0<n<=15）:");
		scanf("%d", &n);
		if(n>0 && n<=15 && n%2!=0){
			printf("矩阵阶数为：%d\n", n);
			break;
		}
	}	 	
	
	//初始化矩阵
	for(i=1; i<=n; ++i){
		for(j=1; j<=n; ++j)
			array[i][j] = 0;
	}
	//规则(1)：将1放在第一行中间一列
	i = 1;
	j = n/2 + 1;
	array[1][j] = 1;
	//规则（2）：从2开始知道n＊n止各数依次按下列规则存放：每一个数存放的行比前一个数的行数减1，列数加1
	//规则（3）:如果上一个数的行数为1，则下一个数的行数为n
	//规则（4）:当上一个数的列数为n时，下一个数的列数应为1，行数减去1
	//规则（5）:如果按上面规则确定的位置上已有数，或上一个数是第一行第n列时，则把下一个数放在上一个数的下面
	for(num=2; num<=n*n; ++num){
		--i;
		++j;
		if(i < 1 && j > n){
			i = i + 2;
			--j;
		}
		else {
			if(j > n)
				j = 1;
			if(i < 1)
				i = n;
		}
		if(array[i][j] == 0)
			array[i][j] = num;
		else {
			i = i + 2;
			--j;
			array[i][j] = num;
		}
	//printf("");
	}

	for(i=1; i<=n; ++i){
		for(j=1; j<=n; ++j)
			printf("%5d",array[i][j]);
		printf("\n");
	}
	printf("\n");
	return 0;
}
