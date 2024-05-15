rpc_clnt_unref (struct rpc_clnt *rpc)
{
        int     count = 0;

        if (!rpc)
                return NULL;
        pthread_mutex_lock (&rpc->lock);
        {
                count = --rpc->refcount;
        }
        pthread_mutex_unlock (&rpc->lock);
        if (!count) {
                rpc_clnt_trigger_destroy (rpc);
                return NULL;
        }
        return rpc;
}