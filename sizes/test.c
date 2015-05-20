#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <setjmp.h>

int main()
{


printf("short int %i\n", sizeof(short int));
printf("int %i\n", sizeof(int));
printf("long %i\n", sizeof(long));

printf("__jmp_buf  %i\n", sizeof(__jmp_buf));
printf("__sigset_t  %i\n", sizeof(__sigset_t));
printf("jmp_buf  %i\n", sizeof(jmp_buf));
printf("sigjmp_buf  %i\n", sizeof(sigjmp_buf));
/* for armv6 */
typedef
        struct __attribute__((__packed__)) My_JmpBuf {
                int jmpbuf[64];
                int maskWasSaved;
                int savedMask[32];
        } My_JmpBuf;

/* for x86_64
typedef
        struct My_JmpBuf {
                long jmpbuf[8];
                int maskWasSaved;
                long savedMask[16];
         } My_JmpBuf;
*/
printf("My_JmpBuf  %i\n", sizeof(My_JmpBuf));

long n, m;
jmp_buf j;

//n=&j[0].__mask_was_saved;
n=&j[0].__saved_mask;
m=&j[0];
printf("offset %i\n", n-m);
}

