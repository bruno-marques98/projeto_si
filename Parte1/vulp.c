/* vulp.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define DELAY 5000
int main()
{
 char *fn = "./XYZ";
 char buffer[60];
 FILE *fp;
 long i;
 /* get user input */
 scanf("%50s", buffer );
 if(access(fn, W_OK) == 0){
 for ( i = 0 ; i < DELAY; i++) {
 int a = i ^ 2;
 }
 fp = fopen(fn, "a+");
 fwrite(buffer, sizeof(char), strlen(buffer), fp);
 fwrite("\n", sizeof(char), 1, fp);
 fclose(fp);
 }
 else printf("No permission \n");
}
