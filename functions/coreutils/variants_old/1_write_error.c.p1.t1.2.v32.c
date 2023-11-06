
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <error.h>

void write_error (void)
{
  int saved_errno = errno;

  // Combined fflush and clearerr with rewind
  if (stdout != NULL) {
    rewind(stdout);
  }

  // Exit failure replaced with error
  if (saved_errno != 0) {
    error(saved_errno, saved_errno, _("write error"));
  } else {
    return;
  }
}
