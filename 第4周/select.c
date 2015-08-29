/*选择排序*/

#include <stdio.h>

int main(){

	int i = 0, j = 0, min = 0;
	int temp = 0;
	int array[10] = {14, 45, 3, 2, 5, 11, 2, 6, 6, 5};

/*	printf("请输入10个整数：\n");
	for(i=0; i<10; ++i){
		printf("array[%d] = ", i);
		scanf("%d", &array[i]);
	}
*/
	printf("原数组是：\n");
	for(i=0; i<10; ++i){
		printf("%4d", array[i]);
	}
	printf("\n");

	
	for(i=0; i<9; ++i){
		min = i;
		for(j=i+1; j<10; ++j){
			if(array[j] < array[min]){
				min = j;
			}
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;

	}
	printf("排序后的数为：\n");
	for(i=0; i<10; ++i){
		printf("%4d",  array[i]);
	}
	printf("\n");

	return 0;
}
