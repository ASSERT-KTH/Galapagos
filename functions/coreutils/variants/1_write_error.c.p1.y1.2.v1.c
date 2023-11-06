Variant 1:

void write_error(void)
{
    int savedErrno = errno;
    fflush(stdout);  
    clearerr(stdout);  
    char err_msg[50];
    strerror_r(savedErrno, err_msg, sizeof(err_msg));
    perror(err_msg);
    exit(EXIT_FAILURE);
}

Variant 2:

void write_error(void)
{
   int errorCode = errno;
   fflush(stdout);
   clearerr(stdout);
   perror(strerror(errorCode));
   exit(EXIT_FAILURE);
}

Variant 3:

void write_error (void)
{
  int errno_saved = errno;
  if(stdout != NULL){
    fflush (stdout);
    clearerr (stdout);
  }
  fprintf(stderr, "%s\n", strerror(errno_saved));
  exit(EXIT_FAILURE);
}

Variant 4:

void write_error(void)
{
   int error_num = errno;
   fflush(stdout);
   clearerr(stdout);
   fprintf(stderr, _("write error: %s\n"), strerror(error_num));
   exit(EXIT_FAILURE);
}

Variant 5:

void write_error(void)
{
   int errno_copy = errno;
   fflush(stdout);  
   clearerr(stdout);  
   fputs(strerror(errno_copy), stderr);
   exit(EXIT_FAILURE);
}
