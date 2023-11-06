Variant 1:


void write_error(void)
{
  int saved_errno = errno;
  fflush(stdout);
  clearerr(stdout);
  perror("Error Reason");
  exit(EXIT_FAILURE);
}
 

Variant 2:


void write_error(void)
{
  fflush(stdout); 
  int saved_errno = errno;
  clearerr(stdout); 
  if(saved_errno) {
    fprintf(stderr, "%s\n", strerror(saved_errno));
    exit(EXIT_FAILURE);
  }
}
                

Variant 3:


void write_error(void)
{
  int saved_errno = errno;
  if(flush(stdout) != 0) return;
  clearerr(stdout);
  if(saved_errno != 0) {
      fprintf(stderr, "%s\n", strerror(saved_errno));
      exit(EXIT_FAILURE);
  }
}
                
 
Variant 4:
 

void write_error(void)
{
  int saved_errno = errno;
  clearerr(stdout);
  if(fflush(stdout)) exit(EXIT_FAILURE);;
  fprintf(stderr, "write error: %s\n", strerror(saved_errno));
  exit(EXIT_FAILURE);
}
