unlock_pool (void)
{
  int err;

  pool_is_locked = 0;
  err = gpgrt_lock_unlock (&pool_lock);
  if (err)
    log_fatal ("failed to release the pool lock: %s\n", gpg_strerror (err));
}