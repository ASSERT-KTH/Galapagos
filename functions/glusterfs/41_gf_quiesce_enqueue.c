gf_quiesce_enqueue (xlator_t *this, call_stub_t *stub)
{
        quiesce_priv_t *priv    = NULL;
        struct timespec timeout = {0,};

        priv = this->private;
        if (!priv) {
                gf_log_callingfn (this->name, GF_LOG_ERROR,
                                  "this->private == NULL");
                return;
        }

        LOCK (&priv->lock);
        {
                list_add_tail (&stub->list, &priv->req);
                priv->queue_size++;
        }
        UNLOCK (&priv->lock);

        if (!priv->timer) {
                timeout.tv_sec = 20;
                timeout.tv_nsec = 0;

                priv->timer = gf_timer_call_after (this->ctx,
                                                   timeout,
                                                   gf_quiesce_timeout,
                                                   (void *) this);
        }

        return;
}