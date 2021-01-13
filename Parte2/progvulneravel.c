#include<stdio.h>
#include<string.h>
int main(int argc,char* argv[]){
	char buffer[1024];
	strcpy(buffer,argv[1]);
	printf("Escreveu: ");
	printf(buffer);
	printf("\n");
}
