gcry_control (enum gcry_ctl_cmds cmd, ...)
{
  gcry_error_t err;
  va_list arg_ptr;

  va_start (arg_ptr, cmd);
  err = gpg_error (_gcry_vcontrol (cmd, arg_ptr));
  va_end(arg_ptr);
  return err;
}