unlock_slot (int slot)
{
#ifdef USE_NPTH
  int err;

  err = npth_mutex_unlock (&reader_table[slot].lock);
  if (err)
    log_error ("failed to release apdu lock: %s\n", strerror (errno));
#endif /*USE_NPTH*/
}