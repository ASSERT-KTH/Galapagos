#include <setjmp.h>
#include <sys/cdefs.h>

#define __USE_GNU
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>

int a = 0;
short b = 5, c;
void sgh(int signal, siginfo_t *si, void *context){
    printf("CAUGHT: %d\n", signal);
    const int return_delta = 0x7;
    ((ucontext_t*)context)->uc_mcontext.gregs[REG_RIP] += return_delta;
}

__attribute__((noinline))
void empty(){
      printf("\n");
 int x = 1;
}

__attribute__((noinline))
int foo() {
  short e = -1;
  unsigned short f;
  char g = 25;
  long h = 0;
  if (a) {
    h = -1;
    g = 0;
  }
  short i = ~g;
  unsigned j = g;
  if (b) {
    f = (h | (i | (583 | j))) ^ ~(~(g & 5L) / e);
    c = 22 / (8UL - (f - 0));
    if (f > 0){
      putc('\0', stdout);
    }
  }
  int k = h % c;

  short l = f ^ 5L;
  if (l){
    a = k;
  }

  if (a != 0){
      a = 0;
      return 1;
  }

  return 0;
}

int main(){
    struct sigaction sa = {0};
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = sgh;
    sa.sa_flags = SA_SIGINFO;

    // Install signal handler
    sigaction(SIGFPE, &sa, NULL);
  printf("RETURN: %d\n", foo());
}
