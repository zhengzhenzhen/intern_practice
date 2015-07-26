#include <stdio.h>

void convert(int *p, int n);

int main(){

	int i = 0;
	int array[11] = {1,2,3,4,5,6,7,8,9,10,11};
	printf("原数据为：\n");
	for(i=0; i<11; ++i){
		printf("%2d", array[i]);
	}
	printf("\n");
	printf("逆序为：\n");
	convert(array, 11);
	for(i=0; i<11; ++i){
		printf("%2d", array[i]);
	}
	return 0;
}

void convert(int *p, int n){
	int *min, *max;
	int mid;
	int *l;
	int temp;
	min = p;
	max = p+n-1;
	mid = (n+1)/2;
	l = p+mid;
	for(; min<=l; ++min, --max){
		temp = *min;
		*min = *max;
		*max = temp;
	}
}
