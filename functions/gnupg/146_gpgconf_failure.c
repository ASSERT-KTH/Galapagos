gpgconf_failure (gpg_error_t err)
{
  log_flush ();
  if (!err)
    err = gpg_error (GPG_ERR_GENERAL);
  gpgconf_write_status
    (STATUS_FAILURE, "- %u",
     gpg_err_code (err) == GPG_ERR_USER_2? GPG_ERR_EINVAL : err);
  exit (gpg_err_code (err) == GPG_ERR_USER_2? 2 : 1);
}