CURLcode win32_init(void)
{
  /* curlx_verify_windows_version must be called during init at least once
     because it has its own initialization routine. */
  if(curlx_verify_windows_version(6, 0, 0, PLATFORM_WINNT,
                                  VERSION_GREATER_THAN_EQUAL))
    tool_isVistaOrGreater = true;
  else
    tool_isVistaOrGreater = false;

  QueryPerformanceFrequency(&tool_freq);

  init_terminal();

  return CURLE_OK;
}