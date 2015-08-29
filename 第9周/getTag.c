#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "gumbo.h"

//将html文件一个字节一个字节地读入内存
static void readFile(FILE *fp, char** output, int* length){
	struct stat filestats;
	int fd = fileno(fp);
	fstat(fd, &filestats);
	*length = filestats.st_size;
	*output = malloc(*length + 1);
	int start = 0;
	int bytes_read;
	while((bytes_read = fread(*output+start, 1, *length-start, fp))){
		start += bytes_read;
	}
}

static const void findTag(const GumboNode* root, int layer){ //layer代表层数
	//用于递归结束条件
	if(root->type != GUMBO_NODE_ELEMENT){
		return;
	}
	//while的功能是缩进格式
	int indent = layer;
	while(indent--){
		printf("  ");
	}
	//获取标签名
	const char* tag_name = gumbo_normalized_tagname(root->v.element.tag);
	printf("%d--------%s\n", layer, tag_name);
	//
	const GumboVector* rchildren = &root->v.element.children;
	for(unsigned int i = 0; i < rchildren->length; ++i){
		GumboNode* child =  rchildren->data[i];
		findTag(child, layer+1);	
	}
}


int main(int argc, const char** argv){
	if(argc != 2){
		printf("得到html文件的各个节点（请加上html文件名作为执行参数）");
		exit(1);
	}
	const char* filename = argv[1];
	//
	FILE *fp;
	if(!(fp = fopen(filename, "r"))){
		printf("file open error!");
		exit(1);
	}
	//
	char* input;
	int length;
	readFile(fp, &input, &length);
	//
	GumboOutput* output = gumbo_parse_with_options(
		&kGumboDefaultOptions, input, length);
	findTag(output->root, 0);
	//
	gumbo_destroy_output(&kGumboDefaultOptions, output);
	fclose(fp);
	free(input);
}


