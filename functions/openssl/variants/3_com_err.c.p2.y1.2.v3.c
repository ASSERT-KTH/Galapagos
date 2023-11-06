int KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    int ret_value;
    va_list ap;

    va_start(ap, fmt);
    if(code != SUCCESS_ERRCODE)       // Execute only when non success Error code are detected.
    {
      ret_value = com_err_va(whoami, code, fmt, ap);
    }
    else
    {
      printf("%s: success.\n", whoami);   // Print when success error code are detected.
      ret_value = 0;
    }

    va_end(ap);

    return ret_value;   // Return function execution status (0 or some error code)
}