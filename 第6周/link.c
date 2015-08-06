/*顺序建立一个整数链表*/

#include <stdio.h>
#include <stdlib.h>

struct link{
	int value;
	struct link *next;	
};

struct link *create(){
	struct link *head, *tail, *p;
	//struct link *head, *p;
	int v;
	//head = NULL;
	head = tail = NULL;
	printf("请输入数据：");

	//新输入的整数接在链表末尾
	while(scanf("%d", &v) == 1){
		p = (struct link*) malloc(sizeof(struct link));
		p->value = v;
		p->next = NULL;
		if(head == NULL){
			head = tail = p;
		}else{
			tail->next = p;
			//tail = tail->next;
			tail = p;
		}
	}

/*	//新输入的整数接在链表头部
	while(scanf("%d", &v) == 1){
		p = (struct link*) malloc(sizeof(struct link));
		p->value = v;
		if(head == NULL){
			p->next = NULL;
			head = p;
		}else{
			p->next = head;
			head = p;	
		}
	}
*/

	return head;
}

int main(){
	struct link *p, *q;
	q = create();
	while(q){
		printf("%d  ", q->value);
		p = q->next;
		free(q);
		q = p;	
	}
	return 0;
}
