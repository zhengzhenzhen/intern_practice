#include <stdio.h>

int main(){
	int i = 0, j = 0;
	int min = 0;
	int temp = 0;
	int array[10] = {3, 2, 1, 44, 23, 12, 5, 5, 2, 12};

	printf("原数据为：\n");
	for(i=0; i<10; ++i){
		printf("%4d", array[i]);
	}
	printf("\n");
	
	for(i=0; i<9; ++i){
		//min = array[i];
		for(j=i+1; j<10; ++j){
			if(array[j] < array[i]){
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}

	printf("排序后的数据为：\n");
	for(i=0; i<10; ++i){
		printf("%4d", array[i]);
	}
	printf("\n");
	return 0;
}
