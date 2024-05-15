mem_pool_destroy (struct mem_pool *pool)
{
        if (!pool)
                return;

        gf_log (THIS->name, GF_LOG_INFO, "size=%lu max=%d total=%"PRIu64,
                pool->padded_sizeof_type, pool->max_alloc, pool->alloc_count);

        list_del (&pool->global_list);

        LOCK_DESTROY (&pool->lock);
        GF_FREE (pool->name);
        GF_FREE (pool->pool);
        GF_FREE (pool);

        return;
}