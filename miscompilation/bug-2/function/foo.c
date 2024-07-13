int foo(int f, int g) {
  if (f - g < 10000)
    return f;
  return f + 1 % -f;
}
