#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

void wait_seconds(float double);

int main() {
  int i, ppid, child_pid;

  ppid = getpid();

  printf("Forking pid: %d\n", ppid);
  child_pid = fork();

  if(child_pid == 0){
    wait_seconds(2.5);
    printf("Finishing pid: %d\n", getpid());
  }
  else{
    wait_seconds(3.0);
    printf("Finishing pid: %d, parent of pid: %d\n", ppid, child_pid);
  }

	return 0;
}

void wait_seconds(float double){
  time_t start, end;

  /* wait 2.5 seconds */
  time(&start);
  do time(&end); while(difftime(end, start) <= time);

  return;
}
