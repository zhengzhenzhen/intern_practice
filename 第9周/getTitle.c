#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>

#include "gumbo.h"

static void read_file(FILE* fp, char** output, int* length){
	struct stat filestats;
	int fd = fileno(fp);//返回文件描述符
	fstat(fd, &filestats);
	*length = filestats.st_size;
	*output = malloc(*length + 1);
	int start = 0;
	int bytes_read;
	while((bytes_read = fread(*output+start, 1, *length - start, fp))){
		start += bytes_read;
	}
}
//
static const char* find_title(const GumboNode* root){
	assert(root->type == GUMBO_NODE_ELEMENT);
	assert(root->v.element.children.length >= 2);
	//
	const GumboVector* root_children = &root->v.element.children;
	GumboNode* head = NULL;
	for(int i=0; i<root_children->length; ++i){
		GumboNode* child = root_children->data[i];
		if(child->type == GUMBO_NODE_ELEMENT && 
		   child->v.element.tag == GUMBO_TAG_HEAD){	
			head = child;
			break;
		}
	}
	assert(head != NULL);
	//
	GumboVector* head_children = &head->v.element.children;
	for(int i=0; i<head_children->length; ++i){
		GumboNode* child = head_children->data[i];
		if(child->type == GUMBO_NODE_ELEMENT && 
		   child->v.element.tag == GUMBO_TAG_TITLE){
			if(child->v.element.children.length != 1){
				return "空的标题!";
			}
		GumboNode* title_text = child->v.element.children.data[0];
		//
		assert(title_text->type == GUMBO_NODE_TEXT ||title_text->type ==GUMBO_NODE_WHITESPACE);
		//
		return title_text->v.text.text;
		}
	}
	return "没有找到标题！";
} 

int main(int argc, const char** argv){
	if(argc != 2){
		printf("Usage:getTitle(html文件).\n");
		exit(EXIT_FAILURE);
	}
	const char* filename = argv[1];
	//
	FILE *fp = fopen(filename, "r");
	if(!fp){
		printf("文件%s没有找到！\n", filename);
		exit(EXIT_FAILURE);	
	}
	//
	char* input;
	int input_length;
	//
	read_file(fp, &input, &input_length);
	GumboOutput* output = gumbo_parse_with_options(
		&kGumboDefaultOptions, input, input_length);
	const char* title = find_title(output->root);
	printf("%s\n", title);
	//
	gumbo_destroy_output(&kGumboDefaultOptions, output);
	fclose(fp);
	free(input);
}
