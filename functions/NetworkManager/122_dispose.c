dispose(GObject *object)
{
    NMFakeNDiscPrivate *priv = NM_FAKE_NDISC_GET_PRIVATE(object);

    nm_clear_g_source(&priv->receive_ra_id);

    g_slist_free_full(priv->ras, fake_ra_free);
    priv->ras = NULL;

    G_OBJECT_CLASS(nm_fake_ndisc_parent_class)->dispose(object);
}