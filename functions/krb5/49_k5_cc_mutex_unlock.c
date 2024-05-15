k5_cc_mutex_unlock(krb5_context context, k5_cc_mutex *m)
{
    /* verify owner and sanity check refcount */
    if ((m->owner != context) || (m->refcount < 1)) {
        return;
    }
    /* decrement & unlock when count reaches zero */
    m->refcount--;
    if (m->refcount == 0) {
        m->owner = NULL;
        k5_mutex_unlock(&m->lock);
    }
}