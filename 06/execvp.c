#include <unistd.h> // execvp()
#include <stdio.h>  // printf()
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

int main(void) {
  char *const cmd[] = {"Head", "-n", "3", "execvp.c", NULL};
  execvp(cmd[0], cmd);
  printf("Return from execvp() not expected\n");
  exit(EXIT_FAILURE);
}

