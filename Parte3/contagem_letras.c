#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



int main(int argc,char** argv)
{
	FILE *arq;
	char filename[50];
	scanf("%s", filename);
	printf("%s\n", filename);
	arq = fopen(filename, "r");
	char nextline[1024];
	
	
	if (arq == NULL)
	{
	   	printf("File not openned\n");
    		return 0;
	}

	int counts[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	char abc[26]= {'a','b','c','d','e','f','g','h','i','j','l','k','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	for(int i = 0; i < 26 ; i++){
		printf("Letra %c:\n", abc[i]);
	}
	
	while (fgets(nextline, sizeof(nextline), arq)){
		//printf("%s\n", nextline);
		if (strlen(nextline) < 1)
			continue;
		for(int i = 0; i < strlen(nextline); i++){
			if(nextline[i] != '\0')
			{
				for(int j = 0; j < 26; j++){
					//printf("Nextline[i]: %c, ABC[j]: %c\n", nextline[i], abc[j]);
					if(nextline[i] == abc[j]){
						//printf("Letter: %c, ABC: %c, Count %d\n",nextline[i],abc[j], counts[j]);
						counts[j] = counts[j] + 1;
					}
				}
			}
			//printf("Line: %s, count A: %d, count b: %d, count c: %d, count d: %d, count e: %d, count f: %d, count g: %d, count h: %d, count i: %d, count j: %d, count l: %d, count k: %d\n",nextline, counts[0],counts[1],counts[2],counts[3],counts[4],counts[5],counts[6],counts[7],counts[8],counts[9],counts[10],counts[11]);		
		}
	} 
	
	fclose(arq);
	printf("\n\n");
	for(int i = 0; i < 26 ; i++){
		printf("Letra %c: %d\n", abc[i], counts[i]);
	}

}
