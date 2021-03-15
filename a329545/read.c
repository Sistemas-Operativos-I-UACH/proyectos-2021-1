#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char *argv[]) {
  int i=0;
  int d;
  float f;
  long int l;
  FILE *file = NULL;
  int fd = -1;
  char line[300];
///  printf("\ncmdline args count=%d", argc);

  /* First argument is executable name only */
 // printf("\nexe name=%s", argv[0]);

  /*for (i=1; i< argc; i++) {
    printf("\narg%d=%s", i, argv[i]);
  }*/

   /*Open file whose path is passed as an argument */
  //fd = fopen( argv[1], "r" );
  fd = open( argv[1], O_RDONLY );

  /* fopen returns NULL pointer on failure */
  if ( fd != -1 ) {
     char ch1;
    /// printf("\nFile (%s) opened", argv[3]);
   //do {
       ch1 = read(fd, &line, 300);
       printf("%s\n", line);

  // } while (ch1 > 0);
    close(fd);
  }
  else {
    printf("\nCould not open file");
    /* Closing file */
  }

  printf("\n");
  return 0;
}
