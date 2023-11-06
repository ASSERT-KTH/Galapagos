Variant 1:

void write_error (void)
{
  int s_errno = errno;
  fflush(stdout);   
  clearerr(stdout);  
  error(EXIT_FAILURE, s_errno, _("write error"));
}

Variant 2:

void write_error (void)
{
  int err = errno;
  fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, err, _("write error"));  
}


Variant 3:

void write_error (void)
{
  int error_val = errno;
  fflush(stdout);  
  clearerr(stdout);
  error(EXIT_FAILURE, error_val, _("write error"));
}
                     

Variant 4:

void write_error (void)
{
  int e_no = errno;
  fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, e_no, _("write error"));
}
                     
                                 
Variant 5:

void write_error (void)
{
  int errMsgNo = errno;
  fflush(stdout);
  clearerr(stdout);
  error(EXIT_FAILURE, errMsgNo, _("write error"));
}
  

Variant 6:

void write_error (void)
{
    int err_num = errno;
    if (!fflush(stdout)) /* Safe way to flush output is to test for failure */
    {
     clearerr(stdout);
     error(EXIT_FAILURE, err_num, _("write error"));              
      }
}
                                 
