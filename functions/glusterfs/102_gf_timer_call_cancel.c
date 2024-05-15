gf_timer_call_cancel (glusterfs_ctx_t *ctx,
                      gf_timer_t *event)
{
        gf_timer_registry_t *reg = NULL;

        if (ctx == NULL || event == NULL)
        {
                gf_log_callingfn ("timer", GF_LOG_ERROR, "invalid argument");
                return 0;
        }

        reg = gf_timer_registry_init (ctx);
        if (!reg) {
                gf_log ("timer", GF_LOG_ERROR, "!reg");
                GF_FREE (event);
                return 0;
        }

        pthread_mutex_lock (&reg->lock);
        {
                event->next->prev = event->prev;
                event->prev->next = event->next;
        }
        pthread_mutex_unlock (&reg->lock);

        GF_FREE (event);
        return 0;
}