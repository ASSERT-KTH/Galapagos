g10_exit (int rc)
{
  if (rc)
    ;
  else if (log_get_errorcount(0))
    rc = 2;
  else if (g10_errors_seen)
    rc = 1;
  else if (opt.assert_pubkey_algos && assert_pubkey_algo_false)
    rc = 1;

  exit (rc);
}