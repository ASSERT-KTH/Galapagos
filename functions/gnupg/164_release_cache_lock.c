release_cache_lock (void)
{
  int err;

  err = npth_rwlock_unlock (&cert_cache_lock);
  if (err)
    log_fatal (_("can't release lock on the certificate cache: %s\n"),
               strerror (err));
}