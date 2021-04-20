#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    char *p;
    int num;
    char buffer_uno[100];
    char *buffer_dos = malloc(sizeof(char) * 100);

    if(argc == 3){
	long conv = strtol(argv[2], &p, 10);
	num = conv;
        printf("*******Buffer 1*******\n");
        for(int i = 0; i<num; i++){
            printf("Direccion %d: %p\n",i, &buffer_uno[i]);
        }
        printf("*******Buffer 2*******\n");
        for(int i = 0; i<num; i++){
            printf("Direccion %d: %p\n",i, &buffer_dos[i]);
        }
    }
    else{
        printf("*******Buffer 1*******\n");
        printf("Direccion: %p\n",&buffer_uno[0]);

        printf("*******Buffer 2*******\n");
        printf("Direccion: %p\n",&buffer_dos[0]);
    }
}


