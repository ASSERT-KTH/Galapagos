gnupg_process_ctl (gnupg_process_t process, unsigned int request, ...)
{
  va_list arg_ptr;
  gpg_err_code_t ec;

  va_start (arg_ptr, request);
  ec = process_vctl (process, request, arg_ptr);
  va_end (arg_ptr);
  return ec;
}