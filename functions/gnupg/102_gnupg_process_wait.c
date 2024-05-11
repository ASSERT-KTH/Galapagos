gnupg_process_wait (gnupg_process_t process, int hang)
{
  gpg_err_code_t ec;
  int status;
  pid_t pid;

  if (process->terminated)
    /* Already terminated.  */
    return 0;

  pre_syscall ();
  while ((pid = waitpid (process->pid, &status, hang? 0: WNOHANG))
         == (pid_t)(-1) && errno == EINTR);
  post_syscall ();

  if (pid == (pid_t)(-1))
    {
      ec = gpg_err_code_from_syserror ();
      log_error (_("waiting for process %d to terminate failed: %s\n"),
                        (int)pid, gpg_strerror (ec));
    }
  else if (!pid)
    {
      ec = GPG_ERR_TIMEOUT; /* Still running.  */
    }
  else
    {
      process->terminated = 1;
      process->wstatus = status;
      ec = 0;
    }

  return ec;
}