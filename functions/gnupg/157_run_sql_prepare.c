run_sql_prepare (const char *sqlstr, const char *extra, const char *extra2,
                 sqlite3_stmt **r_stmt)
{
  gpg_error_t err;
  int res;
  char *buffer = NULL;

  if (extra || extra2)
    {
      buffer = strconcat (sqlstr, extra?extra:"", extra2, NULL);
      if (!buffer)
        return gpg_error_from_syserror ();
      sqlstr = buffer;
    }

  res = sqlite3_prepare_v2 (database_hd, sqlstr, -1, r_stmt, NULL);
  if (res)
    err = diag_prepare_err (res, sqlstr);
  else
    err = 0;
  xfree (buffer);
  return err;
}