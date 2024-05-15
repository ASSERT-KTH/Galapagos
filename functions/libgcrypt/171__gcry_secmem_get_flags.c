_gcry_secmem_get_flags (void)
{
  unsigned flags;

  SECMEM_LOCK;

  flags = no_warning ? GCRY_SECMEM_FLAG_NO_WARNING : 0;
  flags |= suspend_warning ? GCRY_SECMEM_FLAG_SUSPEND_WARNING : 0;
  flags |= not_locked ? GCRY_SECMEM_FLAG_NOT_LOCKED : 0;
  flags |= no_mlock ? GCRY_SECMEM_FLAG_NO_MLOCK : 0;
  flags |= no_priv_drop ? GCRY_SECMEM_FLAG_NO_PRIV_DROP : 0;

  SECMEM_UNLOCK;

  return flags;
}