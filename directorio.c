    /*

     * C Program to List Files in Directory

     */

    #include <dirent.h>

    #include <stdio.h>

     

    int main(void)

    {

	char nombreDirectorio[50];
	printf("Ingrese el nombre del directorio");
	scanf("%s", nombreDirectorio);


        DIR *d;



        struct dirent *dir;

        d = opendir(nombreDirectorio);

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
