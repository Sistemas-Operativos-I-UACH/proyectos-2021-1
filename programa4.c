#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>


int main (int argc, char *argv[]) {
	

	FILE *fp=NULL;
	fp=fopen(argv[1],"r");
	struct dirent *dir;
	DIR *d;
	d = opendir(argv[1]); 
	printf("codigo de salida %p\n",fp);
	char caracter;
	
	if(fp!=NULL){
	printf("entra");	
		while ((dir = readdir(d)) != NULL)

			printf("%s\n", dir->d_name);
			
				while((caracter=fgetc(fp))!=EOF){

        		{	
					printf("%c",caracter);
            			

       		 }	
       	 
		}

		fclose(fp);
		closedir(d);
		
	}
	
	
	else{
	printf("entra2");
		printf("\nError brother q estas tratando de abrir");
	
	}
	
return 0;
}
