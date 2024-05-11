write_status_failure (const char *where, gpg_error_t err)
{
  static int any_failure_printed;

  if (!statusfp || !status_currently_allowed (STATUS_FAILURE))
    return;  /* Not enabled or allowed. */
  if (any_failure_printed)
    return;
  any_failure_printed = 1;
  es_fprintf (statusfp, "[GNUPG:] %s %s %u\n",
              get_status_string (STATUS_FAILURE), where, err);
  if (es_fflush (statusfp) && opt.exit_on_status_write_error)
    g10_exit (0);
}