int CRYPTO_THREAD_unlock(CRYPTO_RWLOCK *lock)
{
# ifdef USE_RWLOCK
    CRYPTO_win_rwlock *rwlock = lock;

    if (rwlock->exclusive) {
        rwlock->exclusive = 0;
        ReleaseSRWLockExclusive(&rwlock->lock);
    } else {
        ReleaseSRWLockShared(&rwlock->lock);
    }
# else
    LeaveCriticalSection(lock);
# endif
    return 1;
}