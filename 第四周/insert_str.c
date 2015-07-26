/*利用指针数组完成：在一个已排好序的字符串数组中，插入一个键盘输入的字符串，使其继续保持有序*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

int find(char *p[], char *t);
void insert(char *p[], char *t, int loc);

int main(){
	char *pstr[N];//定义一个指针数组
       	//char *temp = 0;
	char *temp;//此处不能赋0或NULL？？ 
	int i = 0;
	
	//为指针数组赋初值
	printf("请输入多个字符串：\n");
	for(; i<N-1; ++i){
		pstr[i] = (char*)malloc(20*1);//动态分配空间
		gets(pstr[i]);
	}
	//此处动态分配一个空间，以便后面输入的一个字符串做插入
	pstr[N-1] = (char*) malloc(20*1);
	
	printf("请输入一个要插入的字符串：\n");
	gets(temp);
	i = find(pstr, temp);
	printf("要插入的位置是%d\n", i);
	//插入字符串
	insert(pstr, temp, i);

	printf("输出插入后的全部字符串为：\n");
	for(i=0; i<N; ++i){
		printf("%s\n", pstr[i]);
	}	
	return 0;
}


//因为是有序的，使用二分查找法，来找到该插入的位置
int find(char *p[], char *t){
	int high = N-2, low = 0, mid = 0;
	if(strcmp(t, p[0]) < 0){
		return 0;
	}
	if(strcmp(t, p[high]) > 0){
		return N-1;
	}
	while(low <= high){
		mid = (low + high)/2;
		if(strcmp(t, p[mid]) < 0){
			high = mid-1;
		}else if(strcmp(t, p[mid]) > 0){
			low = mid+1;
		}else{
			return mid;//与某个mid相等，就插入mid位置
		}
	}
	return low;//最终low的位置就是字符串要插入的位置
}

//将输入的字符串插入其中
void insert(char *p[], char *t, int loc){
	int i = 0;
	for(i=N-1; i>loc; --i){//后移插入位置之后的字符串
		strcpy(p[i], p[i-1]);
	}	
	strcpy(p[loc], t);
}
