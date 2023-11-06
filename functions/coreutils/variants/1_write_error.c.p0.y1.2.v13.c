void write_error (void)
{
  int err_number = errno;
  _Bool err_on_stdout = fflush (stdout);             /* Check if there is any error while flushing the buffer */
  
  if(!err_on_stdout) 
        clearerr (stdout);                   /* No need to clear errors if fflush is failed to flush the buffer */
  else
        error(EXIT_FAILURE, err_number, _("write error"));    /* Here, stdout errors are cleared if flushing buffer is successful */
}