#include "ThreadPool.h"
#include <time.h>
#include <stdio.h>
#include <errno.h>
using namespace Tiny;

void nano_sleep(double val);

void foo()
{
    printf("foo\n");
}

int main(int argc, char const *argv[])
{
    Tiny::ThreadPool pool(100, 4);
    pool.start();

    while(1)
    {
        pool.addTask(&foo);
        nano_sleep(0.5);
    }
    
    return 0;
}


void nano_sleep(double val)
{
    struct timespec tv;
    tv.tv_sec = val; //取整
    tv.tv_nsec = (val - tv.tv_sec) * 1000 * 1000 * 1000;

    int ret;
    do
    {
        ret = nanosleep(&tv, &tv);
    }while(ret == -1 && errno == EINTR);
}