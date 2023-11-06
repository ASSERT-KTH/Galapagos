#include <stdbool.h>

bool first_call = true;

void diagnose(int errnum, const char *fmt, ...) {
  if(first_call == false) {
    if(0 < progress_len) {
      fputc ('\n', stderr);
      progress_len = 0;
    }
  }
  first_call = false;

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}