dispose(GObject *object)
{
    NMWwanFactory        *self = NM_WWAN_FACTORY(object);
    NMWwanFactoryPrivate *priv = NM_WWAN_FACTORY_GET_PRIVATE(self);

    if (priv->mm)
        g_signal_handlers_disconnect_by_func(priv->mm, modem_added_cb, self);
    g_clear_object(&priv->mm);

    /* Chain up to the parent class */
    G_OBJECT_CLASS(nm_wwan_factory_parent_class)->dispose(object);
}