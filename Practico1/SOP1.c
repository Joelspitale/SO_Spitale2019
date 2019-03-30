#include<stdio.h>
int main() {
	int pid;
	pid = fork();
	if (pid == 0) {
		printf("soy el hijo\n");
	} else {
		printf("soy el padre");
	}
return 0;
}
