struct timeval tvnow(void)
{
  struct timeval now;
  if(tool_isVistaOrGreater) { /* QPC timer might have issues pre-Vista */
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    now.tv_sec = (long)(count.QuadPart / tool_freq.QuadPart);
    now.tv_usec = (long)((count.QuadPart % tool_freq.QuadPart) * 1000000 /
                         tool_freq.QuadPart);
  }
  else {
    /* Disable /analyze warning that GetTickCount64 is preferred  */
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:28159)
#endif
    DWORD milliseconds = GetTickCount();
#if defined(_MSC_VER)
#pragma warning(pop)
#endif

    now.tv_sec = (long)(milliseconds / 1000);
    now.tv_usec = (long)((milliseconds % 1000) * 1000);
  }
  return now;
}