int printf(const char *, ...);
static int a = -3, b;
static char c;
int d;
int e(int f, int g) {
    int result = f;
    if (!(f - g < 10000)) {
        result = f + 1 % -f;
    }
    return result;
}
int foo() {
  int *h[] = {&a, &a};
  for (; c <= 37; ++c) {
    int *i = &b;
    *i |= e(a, 8) + d;
  }
  return b;
}

int main(){
   printf("%d\n", foo()); 
}
