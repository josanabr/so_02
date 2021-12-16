/*
 * Este programa muestra como leer varias palabras del teclado (stdin)
 * Codigo tomado de: https://www.programiz.com/c-programming/c-strings
 *
 * Modificado por: John Sanabria - john.sanabria@correounivalle.edu.co
 * Fecha: 2021-02-26
 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "leercadena.h"

int main(int argc, char *argv[]) {
  char comando[BUFSIZ];
  char **vector;
  pid_t pid;

  while (1) {
    printf("$ ");
    leer_de_teclado(BUFSIZ,comando);
    if (strcmp(comando,"salir") == 0) { // comando == 'salir'
      return 0;
    } else if (strcmp(comando, "exit") == 0) {
      return 1;
    }
    pid = fork();
    if (pid == 0) {
      vector = de_cadena_a_vector(comando);
      execvp(vector[0],vector);
    } else if (pid > 0) {
      wait(NULL);
    } else {
      printf("Error en la ejecucion del 'fork'\n");
      return 1;
    }
  }

  return 0;
}

