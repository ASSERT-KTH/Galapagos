CRYPTO_RWLOCK *CRYPTO_THREAD_lock_new(void)
{
    CRYPTO_RWLOCK *lock;
# ifdef USE_RWLOCK
    CRYPTO_win_rwlock *rwlock;

    if ((lock = CRYPTO_zalloc(sizeof(CRYPTO_win_rwlock), NULL, 0)) == NULL)
        /* Don't set error, to avoid recursion blowup. */
        return NULL;
    rwlock = lock;
    InitializeSRWLock(&rwlock->lock);
# else

    if ((lock = CRYPTO_zalloc(sizeof(CRITICAL_SECTION), NULL, 0)) == NULL)
        /* Don't set error, to avoid recursion blowup. */
        return NULL;

#  if !defined(_WIN32_WCE)
    /* 0x400 is the spin count value suggested in the documentation */
    if (!InitializeCriticalSectionAndSpinCount(lock, 0x400)) {
        OPENSSL_free(lock);
        return NULL;
    }
#  else
    InitializeCriticalSection(lock);
#  endif
# endif

    return lock;
}