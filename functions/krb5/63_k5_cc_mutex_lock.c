k5_cc_mutex_lock(krb5_context context, k5_cc_mutex *m)
{
    /* not locked or already locked by another context */
    if (m->owner != context) {
        /* acquire lock, blocking until available */
        k5_mutex_lock(&m->lock);
        m->owner = context;
        m->refcount = 1;
    }
    /* already locked by this context, just increase refcount */
    else {
        m->refcount++;
    }
}