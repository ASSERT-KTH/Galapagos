CRYPTO_RWLOCK *CRYPTO_THREAD_lock_new(void)
{
    CRYPTO_RWLOCK *lock;

    if ((lock = CRYPTO_zalloc(sizeof(unsigned int), NULL, 0)) == NULL)
        /* Don't set error, to avoid recursion blowup. */
        return NULL;

    *(unsigned int *)lock = 1;

    return lock;
}