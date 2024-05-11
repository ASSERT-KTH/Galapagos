cleanup (void)
{
  if (is_locked)
    {
      if (!dotlock_release (lockhandle))
        is_locked = 0;
    }
}