int glusterd_big_locked_handler (rpcsvc_request_t *req, rpcsvc_actor actor_fn)
{
        glusterd_conf_t *priv = THIS->private;
        int             ret   = -1;

        synclock_lock (&priv->big_lock);
        ret = actor_fn (req);
        synclock_unlock (&priv->big_lock);

        return ret;
}