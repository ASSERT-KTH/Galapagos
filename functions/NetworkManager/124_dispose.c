dispose(GObject *object)
{
    NMNDisc        *ndisc = NM_NDISC(object);
    NMNDiscPrivate *priv  = NM_NDISC_GET_PRIVATE(ndisc);

    nm_clear_g_source_inst(&priv->ra_timeout_source);
    nm_clear_g_source_inst(&priv->solicit_timer_source);
    nm_clear_g_source(&priv->send_ra_id);
    nm_clear_g_free(&priv->last_error);

    nm_clear_g_source_inst(&priv->timeout_expire_source);

    G_OBJECT_CLASS(nm_ndisc_parent_class)->dispose(object);
}