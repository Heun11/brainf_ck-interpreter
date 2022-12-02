#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void run_code(char *code)
{
	char tape[30000];
	for(int i=0;i<30000;i++){
		tape[i] = 0;
	}
	int ptr = 0;
	int loops = 0;
	int i = 0;
	char nextCH;

	while(i<strlen(code)){
		if(code[i]=='+'){
			tape[ptr]+=1;
			if(tape[ptr]>255){
				tape[ptr] = 0;
			}
		}
		else if(code[i]=='-'){
			tape[ptr]-=1;
			if(tape[ptr]<0){
				tape[ptr] = 255;
			}
		}

		else if(code[i]=='>'){
			if(ptr<29999){
				ptr+=1;
			}
		}
		else if(code[i]=='<'){
			if(ptr>0){
				ptr-=1;
			}
		}
		else if(code[i]=='.'){
			printf("%c", tape[ptr]);
		}
		else if(code[i]==','){
			tape[ptr] = getchar();
			nextCH = getchar();
		}

		else if(code[i]=='['){
			if(tape[ptr]==0){
				loops = 1;
				while(loops>0){
					i+=1;
					if(code[i]=='['){
						loops+=1;
					}
					else if(code[i]==']'){
						loops-=1;
					}
				}
			}
		}
		else if(code[i]==']'){
			loops = 1;
			while(loops>0){
				i-=1;
				if(code[i]=='['){
					loops-=1;
				}
				else if(code[i]==']'){
					loops+=1;
				}
			}
			i-=1;
		}

		i+=1;
	}
}

int main(int argc, char *argv[])
{
	if(argc<=1){
		printf("No file!\n");
		exit(0);
	}

	FILE *src = fopen(argv[1], "r");
	char *buff;
	long numbytes;

	if(src==NULL){
		printf("Error opening file!\n");
		exit(0);
	}

	fseek(src, 0L, SEEK_END);
	numbytes = ftell(src);
	fseek(src, 0L, SEEK_SET);
	buff = (char*)calloc(numbytes, sizeof(char));
	if(buff==NULL){
		printf("Error with memory loading!\n");
		exit(0);
	}
	fread(buff, sizeof(char), numbytes, src);
	fclose(src);

	// printf("%s\n", buff);

	run_code(buff);

	return 0;
}
