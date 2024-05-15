struct curltime Curl_now(void)
{
  struct curltime now;
  if(Curl_isVistaOrGreater) { /* QPC timer might have issues pre-Vista */
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    now.tv_sec = (time_t)(count.QuadPart / Curl_freq.QuadPart);
    now.tv_usec = (int)((count.QuadPart % Curl_freq.QuadPart) * 1000000 /
                        Curl_freq.QuadPart);
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

    now.tv_sec = milliseconds / 1000;
    now.tv_usec = (milliseconds % 1000) * 1000;
  }
  return now;
}