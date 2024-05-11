gnupg_sleep (unsigned int seconds)
{
#ifdef USE_NPTH
  npth_sleep (seconds);
#else
  /* Fixme:  make sure that a sleep won't wake up to early.  */
# ifdef HAVE_W32_SYSTEM
  Sleep (seconds*1000);
# else
  sleep (seconds);
# endif
#endif
}