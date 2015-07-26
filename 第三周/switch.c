/*逆序输出一个正整数，并求出它的位数*/

#include <stdio.h>
#define TRUE 1

int main(){
	//
	int num = 0,  place = 0;
	int indiv = 0, ten = 0 , hundred = 0, thousand = 0, ten_thousand = 0;
	//
	printf("请输入一个正整数（不超过5位数）：");
	while(TRUE){
		scanf("%d", &num);
		//
		if(num > 0 && num < 10){
			place = 1;
			break;
		}else if(num >= 10 && num < 100){
			place = 2;
			break;
		}else if(num >= 100 && num < 1000){
			place = 3;
			break;
		}else if(num >=1000 && num < 10000){
			place = 4;
			break;
		}else if(num >=10000 && num < 100000){
			place = 5;
			break;
		}
			printf("输入错误，请输入不超过5位的正整数：");
			
		
	}		
	printf("是%d位数\n", place);
	//
	ten_thousand = num / 10000;
	thousand = ( num - ten_thousand*10000 ) / 1000 ; 
	hundred = ( num - thousand*1000 - ten_thousand*10000 ) / 100 ;
	ten = ( num - hundred*100 - thousand*1000 - ten_thousand*10000 ) / 10;
	indiv = num - (ten*10 + hundred*100 + thousand*1000 + ten_thousand*10000);
	//
	//利用位数来打印出整数的结果
	switch(place){
		case 1:
			printf("逆序为:%d\n", indiv );
			break;
		case 2:
			printf("逆序输出为:%d%d\n", indiv, ten);
			break;
		case 3:
			printf("逆序输出为：%d%d%d\n ", indiv, ten, hundred );
			break;
		case 4:
			printf("逆序输出为：%d%d%d%d\n", indiv, ten, hundred, thousand );
			break;
		case 5:
			printf("逆序输出为：%d%d%d%d%d\n", indiv, ten, hundred, thousand, ten_thousand );
			break;
		default:
			break;
	}
	return 0;	
}
