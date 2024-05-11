session_env_setenv (session_env_t se, const char *name, const char *value)
{
  if (!name || !*name)
    return gpg_error (GPG_ERR_INV_VALUE);
  if (!value)
    return delete_var (se, name);
  else
    return update_var (se, name, strlen (name), value, 0);
}