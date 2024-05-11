kbxd_exit (int rc)
{
  /* As usual we run our cleanup handler.  */
  cleanup ();

  /* at this time a bit annoying */
  if ((opt.debug & DBG_MEMSTAT_VALUE))
    gcry_control (GCRYCTL_DUMP_MEMORY_STATS );
  rc = rc? rc : log_get_errorcount(0)? 2 : 0;
  exit (rc);
}