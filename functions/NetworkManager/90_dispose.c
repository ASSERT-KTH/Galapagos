dispose(GObject *object)
{
    NMAtmManager        *self = NM_ATM_MANAGER(object);
    NMAtmManagerPrivate *priv = NM_ATM_MANAGER_GET_PRIVATE(self);
    GSList              *iter;

    for (iter = priv->devices; iter; iter = iter->next)
        g_object_weak_unref(G_OBJECT(iter->data), device_destroyed, self);
    nm_clear_pointer(&priv->devices, g_slist_free);

    priv->udev_client = nm_udev_client_destroy(priv->udev_client);

    G_OBJECT_CLASS(nm_atm_manager_parent_class)->dispose(object);
}