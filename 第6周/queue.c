/*队列的操作*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/*typedef struct{
	int data;
	Queue *next;
}Queue, *Que_link;

typedef struct{
	Que_link front;
	Que_link rear;
}Link_que;
*/


typedef struct{
	int *data;
	int front;
	int rear;
}Queue;

void init_queue(Queue *queue);
int insert(Queue *queue, int v);
int delete(Queue *queue, int *x);
int que_len(Queue *queue);

int main(){
//	Queue *queue = NULL;
	Queue *queue ;
	queue = (Queue *) malloc(sizeof(Queue));
	int i, v, m, n;
	int a;
	//int *x;
	init_queue(queue);
	printf("\n");	

	printf("要插入队列的字符个数：\n");
	scanf("%d", &m);
	printf("输入整数数据：\n");
	for(i=0; i<m; ++i){
		scanf("%d", &v);
		a = insert(queue, v);
		if(!a){
			break;
		}
	}

	a = que_len(queue);
	printf("队列长度为：%d\n", a);

	printf("要删除队列的字符个数：\n");
	scanf("%d", &n);
	printf("从队列中删除的数据是：\n");
	for(i=0; i<n; ++i){
		if(!delete(queue, &v)){
			break;
		}	
		printf("%d\n", v);
	}
	free(queue->data);
	free(queue);
	return 0;
}

//初始化队列
void init_queue(Queue *queue){
	queue->data = (int *) malloc(MAX * sizeof(int));
	if(!queue->data){
		printf("分配内存失败！");
		exit(0);
	}
	queue->front = queue->rear = 0;
	printf("队列初始化成功！");
}

//向队列中插入元素
int insert(Queue *queue, int v){
	/*为了将队列满与队列空区别开，于是少用一个元素空间，
	约定队列头指针在队列尾指针的下一位置上为"满"*/
	if(((queue->rear)+1) % MAX == (queue->front)){
		printf("队列已满！\n");
		return 0;
	}
	queue->data[queue->rear] = v;
	queue->rear = (queue->rear + 1) % MAX;
	return 1;
}

//删除队列元素
int delete(Queue *queue, int *x){
	if(queue->front == queue->rear){
		printf("队列为空！\n");
		return 0;
	}
	*x = queue->data[queue->front];
	queue->front = (queue->front + 1) % MAX; //想象成一个循环队列
	return 1;
}

//返回队列长度，即元素个数
int que_len(Queue *queue){
	return (queue->rear - queue->front + MAX) % MAX;
}








