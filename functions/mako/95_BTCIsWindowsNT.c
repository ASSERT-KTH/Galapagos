BTCIsWindowsNT(void) {
  static volatile long state = 0;
  static DWORD version = 0;
  long value;

  while ((value = InterlockedCompareExchange(&state, 1, 0)) == 1)
    Sleep(0);

  if (value == 0) {
    version = GetVersion();

    if (InterlockedExchange(&state, 2) != 1)
      abort(); /* LCOV_EXCL_LINE */
  } else {
    assert(value == 2);
  }

  return version < 0x80000000;
}