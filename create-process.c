#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

void wait_seconds(float time_to_wait);

int main() {
  int proc, g_proc, ppid;

  printf("Init pid: %d\n", getpid());
  proc = fork();

	if(proc == 0){
    printf("Get pid: %d\n", getpid());
		g_proc = fork();
		if (g_proc == 0) {
			printf("Processo 1\n");
      //printf("Finishing pid: %d\n", getpid());

		} else {
			//RETIRE O COMENTÁRIO DA LINHA ABAIXO PARA TESTAR STARVATION
			//wait4(g_proc, NULL, 0, NULL);
			printf("Processo 2\n");
      //printf("Finishing pid: %d\n", getpid());
			}
	} else{
		printf("Processo 3\n");

	}
  printf("Finishing pid: %d\n", getpid());
  return 0;
}

void wait_seconds(float time_to_wait){
  time_t start, end;

  /* wait 2.5 seconds */
  time(&start);
  do time(&end); while(difftime(end, start) <= time_to_wait);


  return;
}
