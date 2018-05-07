#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "/usr/src/minix/kernel/ipc.h"
#include "/usr/src/minix/servers/pm/mproc.h"

#include "/usr/src/minix/servers/pm/mproc.h"

#include "/usr/src/minix/servers/is/inc.h"


void do_printpids();

int main(int argc, char **argv)
{
  if (strcmp(argv[1], "-help") == 0){

    printf("------------------------------------\n");
    printf("  Commands enable      \n");
    printf("------------------------------------\n\n");
    printf("  Process State          (-ps) - Mostra o estado de todos os processos que atualmente se encontram no sistema\n");
    printf("  Running                (-r <pid/endpoint>) - Recebe por argumento o número de processo <pid/endpoint>. Este modo muda o processo <pid/endpoint> de seu estado atual ao estado executável.\n");
    printf("  Sleep                  (-s <pid/endpoint>) - Recebe por argumento o número de processo <pid/endpoint>. Este modo muda o processo <pid/endpoint> de seu estado atual ao estado dormindo.\n");
    printf("  Stoped                 (-t <pid/endpoint>) - Recebe por argumento o número de processo <pid/endpoint>. Este modo muda o processo pid/endpoint> de seu estado atual ao estado detido.\n");
    printf("  Zombie                 (-z <pid/endpoint>) - Recebe por argumento o número de processo <pid/endpoint>. Este modo muda o processo pid/endpoint> de seu estado atual ao estado zombie.\n");
    printf("  Exit                   (-e <pid/endpoint>) - Recebe por argumento o número de processo <pid/endpoint>. Este modo deve cerrar (terminar) o processo <pid/endpoint>.\n");
    printf("  Verbose                (-v) - Por padrão, seus comandos são silenciosos e não mostram nenhuma mensagem (a menos que seja um erro). Caso se deseje mostrar informação deverá de ser enviado uma opção verbose que faz ao comando entregar informação do que acontece. As seguintes são opções válidas: -v -t 123, -vt 123, -t 123 -v.\n");
    printf("  Help                   (-help) - Mostra o conjunto de comandos, sua sintaxes, e uma breve descrição de sua funcionalidade.\n");

  }
  else if (strcmp(argv[1], "-ps") == 0){

    // struct kinfo pinf;
    // int num_procs;
    //
    // getsysinfo(PM_PROC_NR, SI_KINFO, &pinf);
    //
    // num_procs = pinf.nr_pro;

    printf("----------------------\n");
    printf(" PID/EndPoint   State\n");
    printf("----------------------\n");
    //printf(" %.3d            %c\n", test, test2);
    printf("%d\n", 10);

  }
  else if (strcmp(argv[1], "-r") == 0){

    printf("Printing PIDS:\n");
    do_printpids();
    printf("Printing PIDS Done\n");

  }
  else if (strcmp(argv[1], "-s") == 0){


  }
  else if (strcmp(argv[1], "-t") == 0){


  }
  else if (strcmp(argv[1], "-z") == 0){


  }
  else if (strcmp(argv[1], "-e") == 0){


  }
  else if (strcmp(argv[1], "-v") == 0){


  }

  printf("HELLO PADMON\n");
	exit(0);
}

void do_printpids(){
  //int i = m_in.m1_i1; //pid received. m_in is a global variable
  int c = 0; //Counter

  //printf("Searching for children of process: %d \n", i);

  while (c < NR_PROCS)
  {
      int n = mproc[c].mp_pid; //First process in the list of availableprocess
      //int pinx = mproc[c].mp_parent; //Index of parent of the current process
      //int ppid = mproc[pinx].mp_pid; //pid of parent process
      printf("Proc: %d, PID: %d\n", c, n);

      // if(i == ppid) //If parents pid matches the given value
      // {
      //   printf("%d \n", n); //Print the childs id
      //   c++;
      // }
      // else
      // {
      //   c++;
      // }
      c++;
  }
  return;
}
