quota_local_new ()
{
        quota_local_t *local = NULL;
        local = mem_get0 (THIS->local_pool);
        if (local == NULL)
                goto out;

        LOCK_INIT (&local->lock);
        local->space_available = -1;

out:
        return local;
}