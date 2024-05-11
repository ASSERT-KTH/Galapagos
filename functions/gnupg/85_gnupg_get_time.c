gnupg_get_time (void)
{
  time_t current = time (NULL);
  if (current == (time_t)(-1))
    log_fatal ("time() failed\n");

  if (timemode == NORMAL)
    return current;
  else if (timemode == FROZEN)
    return timewarp;
  else if (timemode == FUTURE)
    return current + timewarp;
  else
    return current - timewarp;
}