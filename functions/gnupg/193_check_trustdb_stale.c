check_trustdb_stale (ctrl_t ctrl)
{
#ifndef NO_TRUST_MODELS
  tdb_check_trustdb_stale (ctrl);
#else
  (void)ctrl;
#endif
}