#include <dirent.h>

#include <stdio.h>

 

int main(void)

{
	
    DIR *d;
	char direccion[200];
	printf("En que directorio quiere buscar?\n");
	scanf("%s", direccion);

    struct dirent *dir;

    d = opendir(direccion);

    if (d)

    {

        while ((dir = readdir(d)) != NULL)

        {

            printf("%s\n", dir->d_name);

        }

        closedir(d);

    }

    return(0);

}