__owur int CRYPTO_THREAD_write_lock(CRYPTO_RWLOCK *lock)
{
# ifdef USE_RWLOCK
    CRYPTO_win_rwlock *rwlock = lock;

    AcquireSRWLockExclusive(&rwlock->lock);
    rwlock->exclusive = 1;
# else
    EnterCriticalSection(lock);
# endif
    return 1;
}