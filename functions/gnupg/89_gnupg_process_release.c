gnupg_process_release (gnupg_process_t process)
{
  if (!process)
    return;

  if (process->terminated)
    {
      gnupg_process_terminate (process);
      gnupg_process_wait (process, 1);
    }

  xfree (process);
}