/*链表的插入与删除操作*/

#include <stdio.h>
#include <stdlib.h>

struct link{
	int data;
	struct link *next;
};

struct link *create();
struct link *insert(struct link *head, int pre_a, int b);
struct link *delete(struct link *head, int a);

int main(){
	struct link *p, *head;
	//int pre_a, a, b;
	p = create();  //此处的p在堆内存中
	head = p;  //head在栈内存中
	//但p最后释放，否则head就指向未知区域
	printf("输入的链表为：");
	while(p){
		printf("%d ", p->data);
//		q = p->next;
//		free(p);	
//		p = q;
		p = p->next;
	}

	p = insert(head, 3, 5);  //此处的p在栈内存中，所以由系统自动分配释放
	head = p;
	printf("\n");
	printf("将5插入3之前的新链表为：");
	while(p){
		printf("%d ", p->data);
		p = p->next;
	}

	p = delete(head, 3);
	printf("\n");
	if(!p){
		exit(0);	
	}else{
		printf("将3删除后的链表为：");
		while(p){
			printf("%d ", p->data);
			p = p->next;
		}	
	}
	printf("\n");
	free(p);
	return 0;
}

struct link *create(){
	struct link *head, *tail, *cur;
	int i;
	int v;
	head = tail = NULL;
	printf("请输入5个整数：");
	for(i=0; i<5; ++i){
		scanf("%d", &v);
		cur = (struct link*) malloc(sizeof(struct link));
		cur->data = v;
		cur->next = NULL;
		if(head == NULL){
			head = tail = cur;
		}else{
			tail->next = cur;
			tail = cur;
		}	
	}
	return head;
}

//第3个参数是要插入的整数，第2个参数pre_a是查找插入位置的整数，b要插入到pre_a之前
struct link *insert(struct link *head, int pre_a, int b){
	struct link *cur, *pre, *p;
	cur = (struct link*) malloc(sizeof(struct link));
	cur->data = b;
	if(head == NULL){
		head = cur;
		cur->next = NULL; 
	}else if(head->data == pre_a){
		cur->next = head;
		head = cur;
	}else{
		p = head;
		while((p->data != pre_a) && (p->next != NULL)){
			pre = p;
			p = p->next;
		}
		if(p->data == pre_a){
			cur->next  = p;
			pre->next = cur;
		}else{  //不存在查找的点就插入链表尾端
			p->next = cur;
			cur->next = NULL;
		}
	}
	return head;
}

struct link *delete(struct link *head, int a){
	struct link *pre, *p;
	//pre = (struct link*) malloc(sizeof(struct link));
	if(head == NULL){
		printf("空链表");
	}else if(head->data == a){
		head = head->next;
		
	}else{
		p = head;
		while((p->data != a) && (p->next != NULL)){
			pre = p;
			p = p->next;
		}
		if(p->data == a){
			pre->next = p->next;;
			free(p);
		}else{
			printf("\n");
			printf("没有要删除的数据%d\n", a);
			return 0;
			exit(1);
		}
	}
	return head;
}

