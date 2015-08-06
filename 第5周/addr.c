#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void init_list();
int find_free();
void enter();
void del();
void list();
void save();
void load();
int menu_select();

struct addr{
	char name[20];
	char street[40];
	char city[20];
	char state[10];
	unsigned long zip;
} addr_list[MAX];

int main(){
	char choice;
	
	init_list();	
	while(1){
		choice = menu_select();
		switch(choice){
			case 1: enter();
				break;
			case 2: del();
				break;
			case 3: list();
				break;
			case 4: save();
				break;
			case 5: load();
				break;
			case 6: exit(0);
		}
	}	

	return 0;
}

void init_list(){
	register int i;

	for(i=0; i<MAX; ++i){
		addr_list[i].name[0] = '\0';		
	}
}

int find_free(){
	register int i = 0;
	for(; i<=MAX; ++i);

	if(i == MAX){
		return -1;
	}	
	return i;
}

void enter(){
	int s = 0;
	char str[80];

	s = find_free();
	if(s == -1){
		printf("通讯录已满\n");
	}
	printf("输入名字：");
	gets(addr_list[s].name);

	printf("输入街道：");
	gets(addr_list[s].street);

	printf("输入城市：");
	gets(addr_list[s].city);

	printf("输入国家：");
	gets(addr_list[s].state);

	printf("输入邮编：");
	gets(str);
	addr_list[s].zip = strtoul(str, '\0', 10);

}

void del(){
	register int s = 0;
	char str[80];

	printf("输入记录编号#：");
	//gets_s(str, 80);
	gets(str);
	s = atoi(str);

	if(s>=0 && s<MAX){
		addr_list[s].name[0] = '\0';
	}
}

void list(){
	register int i = 0;
	for(; i<MAX; ++i){
		if(addr_list[i].name[0] != '\0'){
			printf("%s\n", addr_list[i].name);
			printf("%s\n", addr_list[i].street);
			printf("%s\n", addr_list[i].city);
			printf("%s\n", addr_list[i].state);
			printf("%lu\n\n", addr_list[i].zip);
		}
	}
	printf("\n\n");
}

void save(){
	FILE *fp;
	int i = 0;
	if((fp=fopen("test", "wb")) == NULL){
		printf("无法打开文件\n");
	}	
	
	for(i=0; i<MAX; ++i){
		if(*addr_list[i].name){
			if(fwrite(&addr_list[i], sizeof(struct addr), 1, fp) != 1){
				printf("file write error\n");
			}
			printf("写入成功");
		}
	}
	fclose(fp);
}

void load(){
	FILE *fp;
	int i = 0;

	if((fp=fopen("test", "rb")) == NULL){
		printf("无法打开文件\n");
	}

	init_list();
	for(i=0; i<MAX; ++i){
		if(fread(&addr_list[i], sizeof(struct addr), 1, fp) != 1){
			printf("file read error\n");
		}
	}
	fclose(fp);
}

int menu_select(){
	char str[80];
	int i = 0;
	
	printf("1.录入信息\n");	
	printf("2.删除名字\n");	
	printf("3.列出通讯录\n");	
	printf("4.保存通讯录到文件\n");	
	printf("5.从文件中加载通讯录\n");	
	printf("6.退出\n");	

	do{
		printf("输入你的选择(1-6):");
		//gets_s(str, 80);
		gets(str);
		i = atoi(str);
	}while(i<0 || i>6);
	
	return i;
}
