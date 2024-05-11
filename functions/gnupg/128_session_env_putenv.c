session_env_putenv (session_env_t se, const char *string)
{
  const char *s;

  if (!string || !*string)
    return gpg_error (GPG_ERR_INV_VALUE);
  s = strchr (string, '=');
  if (s == string)
    return gpg_error (GPG_ERR_INV_VALUE);
  if (!s)
    return delete_var (se, string);
  else
    return update_var (se, string, s - string, NULL, 0);
}