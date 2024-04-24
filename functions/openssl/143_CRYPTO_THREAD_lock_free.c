void CRYPTO_THREAD_lock_free(CRYPTO_RWLOCK *lock)
{
    if (lock == NULL)
        return;

# ifndef USE_RWLOCK
    DeleteCriticalSection(lock);
# endif
    OPENSSL_free(lock);

    return;
}