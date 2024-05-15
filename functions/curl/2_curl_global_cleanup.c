void curl_global_cleanup(void)
{
  global_init_lock();

  if(!initialized) {
    global_init_unlock();
    return;
  }

  if(--initialized) {
    global_init_unlock();
    return;
  }

  Curl_ssl_cleanup();
  Curl_resolver_global_cleanup();

#ifdef _WIN32
  Curl_win32_cleanup(easy_init_flags);
#endif

  Curl_amiga_cleanup();

  Curl_ssh_cleanup();

#ifdef DEBUGBUILD
  free(leakpointer);
#endif

  easy_init_flags = 0;

  global_init_unlock();
}