#include <lib.h>    // provides _syscall and message
#include <stdio.h>
#include <stdlib.h> // provides atoi

int main(int argc, char **argv) {
    if (argc < 3)
        exit(1);    // expecting at least 1 integer parameter to test program

    int i = atoi(argv[1]);
    int j = atoi(argv[2]);

    message m;      // Minix uses message to pass parameters to a system call

    m.m1_i1 = i;    // set first integer of message to i
    m.m1_i2 = j;

    _syscall(PM_PROC_NR, PRINTPPIDS, &m);
        /* _syscall leads to the system server identified by PM_PRO_NR (the PM
         * server process) invoking the function identified by call number
         * PRINTMSG with parameters in the message copied to address &m
         */
}
