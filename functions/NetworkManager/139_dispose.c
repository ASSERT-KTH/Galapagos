dispose(GObject *object)
{
    NMRfkillManager        *self = NM_RFKILL_MANAGER(object);
    NMRfkillManagerPrivate *priv = NM_RFKILL_MANAGER_GET_PRIVATE(self);
    Killswitch             *ks;

    while ((ks = c_list_first_entry(&priv->killswitch_lst_head, Killswitch, killswitch_lst)))
        killswitch_destroy(ks);

    priv->udev_client = nm_udev_client_destroy(priv->udev_client);

    G_OBJECT_CLASS(nm_rfkill_manager_parent_class)->dispose(object);
}