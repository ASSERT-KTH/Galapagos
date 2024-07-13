int printf(const char *, ...);

static int a = -3, b;

static char c;

int d;

int foo(int f, int g) {
  if (f - g < 10000)
    return f;
  return f + 1 % -f;
}

int fn() {
  int *h[] = {&a, &a};
  for (; c <= 37; ++c) {
    int *i = &b;
    *i |= foo(a, 8) + d;
  }
  return b;
}

int main(){
   printf("%d\n", fn()); 
}
