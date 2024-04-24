void CRYPTO_THREAD_lock_free(CRYPTO_RWLOCK *lock) {
    if (lock == NULL)
        return;

    *(unsigned int *)lock = 0;
    OPENSSL_free(lock);

    return;
}