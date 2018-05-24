#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib.h>    // provides _syscall and message

int main(int argc, char **argv)
{
  int ans = 0;
  freopen ("output.txt","w",stdout);
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

    message m;      // Minix uses message to pass parameters to a system call

    m.m1_i1 = 0;    // set first integer of message to i
    m.m1_i2 = 0;

    printf("----------------------\n");
    printf(" PID/EndPoint   State\n");
    printf("----------------------\n");
    _syscall(PM_PROC_NR, PRINTPPIDS, &m);
    printf("----------------------\n");

  }
  //printf("HELLO PADMON\n");
	exit(0);
}
