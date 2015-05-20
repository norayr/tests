#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
       #include <sys/stat.h>
              #include <unistd.h>
#include <setjmp.h>

typedef enum
{
    enum1,
    enum2,
    enum3
}ExampleEnum;

int main()
{


printf("short int %i\n", sizeof(short int));
printf("int %i\n", sizeof(int));
printf("long %i\n", sizeof(long));
printf("long int %i\n", sizeof(long int));
printf("size_t %i\n", sizeof(size_t));
printf("dev_t %i\n", sizeof(dev_t));
printf("ino_t %i\n", sizeof(ino_t));
printf("mode_t %i\n", sizeof(mode_t));
printf("nlink_t %i\n", sizeof(nlink_t));
printf("uid_t %i\n", sizeof(uid_t));
printf("gid_t %i\n", sizeof(gid_t));
printf("off_t %i\n", sizeof(off_t));
printf("blksize_t %i\n", sizeof(blksize_t));
printf("blkcnt_t %i\n", sizeof(blkcnt_t));
printf("time_t %i\n", sizeof(time_t));
//printf("fflags_t  %i\n", sizeof(fflags_t ));
printf("__uint32_t  %i\n", sizeof(__uint32_t));
printf("__int32_t  %i\n", sizeof(__int32_t));

printf("__jmp_buf  %i\n", sizeof(__jmp_buf));
printf("__sigset_t  %i\n", sizeof(__sigset_t));
printf("jmp_buf  %i\n", sizeof(jmp_buf));
printf("sigjmp_buf  %i\n", sizeof(sigjmp_buf));
/*
typedef
        struct Unix_JmpBuf {
                long jmpbuf[64];
                long maskWasSaved;
                long savedMask[32];
        } Unix_JmpBuf;
*/

typedef
struct Unix_JmpBuf {
long jmpbuf[8];
int maskWasSaved;
long savedMask[16];
} Unix_JmpBuf;

printf("Unix_JmpBuf  %i\n", sizeof(Unix_JmpBuf));

typedef
    struct Unix_Status {
        long dev, ino, nlink;
        int mode, uid, gid, pad0;
        long rdev, size, blksize, blocks, atime, atimences, mtime, mtimensec, ctime, ctimensec, unused0, unused1, unused2;
} Unix_Status;

printf("Unix_Status  %i\n", sizeof(Unix_Status));
printf("Stat  %i\n", sizeof(struct stat));

printf("enum %i\n", sizeof(ExampleEnum));
printf("enum1 %i\n", sizeof(enum1));
printf("struct timespec %i\n", sizeof(struct timespec));
printf("struct stat %i\n", sizeof(struct stat));




}

