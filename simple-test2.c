#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

void wait_seconds(float time_to_wait);

int main() {
  int i, ppid, child_pid;

  ppid = getpid();

  printf("Parent pid: %d\n", ppid);
  child_pid = fork();

  if(child_pid == 0){
    for(i = 0; i < 10000000000000; i++);
    printf("Finishing pid: %d\n", getpid());
  }
  else{
    for(i = 0; i < 1000000000000000; i++);
    printf("Finishing pid: %d, parent of pid: %d\n", ppid, child_pid);

  }
	return 0;
}
