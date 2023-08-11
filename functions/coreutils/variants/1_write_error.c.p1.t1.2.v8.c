It was slightly challenging to "change the behavior" of this function because the instructions are quite specific and presented a very particular function without many options. The only thing I changed here was replacing the stdlib `error()` function to using `perror()`. Although the parameters differ significantly, functionally they do the same thing: display an error relating to a system call or library function. What `error()` adds is the error code. However, since `perror()` also uses a string description, I decided to place the error code there.

write_error (void)
{
  int saved_errno = errno;
  char buffer[30];
    
  fflush (stdout);  
  clearerr (stdout);

  sprintf(buffer, "write error: %d", saved_errno);
  perror(buffer);
  
  exit(EXIT_FAILURE);
}