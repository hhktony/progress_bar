/**
 *  Filename: progress_bar.c
 *   Created: 2014-02-22 17:55:06
 *      Desc: TODO (some description)
 *    Author: xutao(Tony Xu), butbueatiful@gmail.com
 *   Company: myself
 */

#include <stdio.h>
#include <signal.h>
#include <math.h>
#include <sys/ioctl.h>

#include "progress_bar.h"

static unsigned g_progress_columns = 0;

static void progress_winch_updater(int sig)
{
	int retval;
	struct winsize wsize;

	if (sig != SIGWINCH)
		return;

	retval = ioctl(1, TIOCGWINSZ, &wsize);
	g_progress_columns = retval < 0 ? 80 : wsize.ws_col;
}

void progress_bar(unsigned current, unsigned max)
{
	int maxdigits = ceil(log10(max));
	int used = maxdigits * 2 + 10;
	int hashes = (current * (g_progress_columns - used)) / max;
	int spaces = g_progress_columns - used - hashes;

	if (g_progress_columns - used < 0)
		return;

	printf("\r[");

	while (hashes-- > 0)
		putchar('=');

	while (spaces-- > 0)
		putchar(' ');

    if (current == max)
        printf("\n");
    else
	    printf("] %*u/%*u", maxdigits, current, maxdigits, max);
	/* printf(" %3u%%", current * 100 / max); */
	fflush(stdout);
}

int progress_init(void)
{
	progress_winch_updater(SIGWINCH);
	signal(SIGWINCH, progress_winch_updater);

	return 0;
}
