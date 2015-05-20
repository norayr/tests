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

//printf("__jmp_buf  %i\n", sizeof(__jmp_buf));
//printf("__sigset_t  %i\n", sizeof(__sigset_t));
printf("jmp_buf  %i\n", sizeof(jmp_buf));
printf("sigjmp_buf  %i\n", sizeof(sigjmp_buf));
/* for armv6 */
/*typedef
        struct __attribute__((__packed__)) my_JmpBuf {
                int jmpbuf[64];
                int maskWasSaved;
                int savedMask[32];
        } my_JmpBuf;
*/
/* for x86_64 linux glibc
typedef
        struct my_JmpBuf {
                long jmpbuf[8];
                int maskWasSaved;
                long savedMask[16];
         } my_JmpBuf;
*/

/* x86_64 darwin 
typedef int jmp_buf[((9 * 2) + 3 + 16)];
typedef int sigjmp_buf[((9 * 2) + 3 + 16) + 1];
*/
typedef int my_JmpBuf[((9 * 2) + 3 + 16)];
printf("my_JmpBuf  %i\n", sizeof(my_JmpBuf));
/*
long n, m;
jmp_buf j;

//n=&j[0].__mask_was_saved;
n=&j[0].__saved_mask;
m=&j[0];
printf("offset %i\n", n-m);
*/
}

