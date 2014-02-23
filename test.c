/**
 *  Filename: test.c
 *   Created: 2014-02-22 16:26:19
 *      Desc: TODO (some description)
 *    Author: xutao(Tony Xu), butbueatiful@gmail.com
 *   Company: myself
 */
#include <unistd.h>

#include "progress_bar.h"

#define PROGRESS_BAR_MAX_WIDTH 100


int main(int argc, char *argv[])
{
    int i, count;

    progress_init ();
    count = 0;

    for (i = 0; i < 10001 ; i++)
    {
        if (i % (10000 / PROGRESS_BAR_MAX_WIDTH) == 0)
        {
            /* count ++; */
            progress_bar (count++, PROGRESS_BAR_MAX_WIDTH);
            usleep(100000);
        }
    }

    return 0;
}
