#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	pid_t pid; // pid_t: pid type
	printf("[%d] Primera instruccion\n",getpid());
        pid = fork();
	if (pid < 0) {
		printf("Error en la creacion del proceso\n");
		return 1;
	} else if (pid == 0) {
		printf("[%d] Soy el hijo\n",getpid());
	} else {
		wait(NULL);
		printf("[%d] Soy el padre y mi hijo es %d\n",getpid(),pid);
	}
	printf("[%d] Segunda instruccion\n",getpid());
	return 0;
}
