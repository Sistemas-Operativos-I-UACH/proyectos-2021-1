#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    char* str1;
    char* str2;
    char* str4;
    char* cmd;
    cmd = "/cmdline";
    str1 = "/proc/";    //proc/ +  1....1000 + /cmdline
    str2 = "1";
    str4 ="/cmdline";
    char * str3 = (char *) malloc(1 + strlen(str1)+ strlen(str2)+ strlen(str4));
    strcpy(str3, str1);
    strcat(str3, str2);
    strcat(str3, str4);
    printf("%s", str3);


    DIR *d, *d2;
    struct dirent *dir, *dir2;
    d = opendir(argv[1]);

    //readfile
    FILE *fp = NULL;
    //fp = fopen(argv[1], "r");
    char caracter;

    
    if(d){
        while((dir = readdir(d)) != NULL){
            if((strcmp(dir->d_name, "..") != 0) && (strcmp(dir->d_name, ".") != 0)){
                printf("%s", dir->d_name);


                char* ruta = (char *) malloc(1 + strlen(str1)+ strlen(dir->d_name));
                strcpy(ruta, str1);
                strcat(ruta, dir->d_name);

                d2 = opendir(ruta);

                if(d2){
                    while((dir2 = readdir(d2)) != NULL){
                        if((strcmp(dir2->d_name, "cmdline") == 0)){
                            char* ruta2 = (char *) malloc(1 + strlen(ruta)+ strlen(cmd));
                            strcpy(ruta2, ruta);
                	    strcat(ruta2, cmd);
                			
                            fp = fopen(ruta2, "r");
                            
                            if(fp!=NULL){
                                printf("\t");
                                while((caracter=fgetc(fp)) != EOF){
                                        printf("%c", caracter);
                                }
                                printf("\n");
                                fclose(fp);
                                }
                                else{
                                        printf("\nNo se encontro el Archivo\n");
                                }
                        }
                        else{
                        	//printf("\n");
                        }
                    }
                    closedir(d2);
                }

            }
        }
        closedir(d);
    } 
    return (0);
}

