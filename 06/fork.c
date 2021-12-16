#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  pid_t pid;
  printf("[%d] Hola mundo\n",getpid());
  pid = fork();
  if (pid < 0 ) {
    printf("Fallo la invocacion de la funcion fork()\n");
    return 1;
  } else if (pid == 0) {
    printf("[%d] Hello world\n",getpid());
  } else {
    wait(NULL);
    printf("[%d] Hola mundo\n",getpid());
  }
  return 0;
}
