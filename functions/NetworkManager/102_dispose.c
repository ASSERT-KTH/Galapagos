dispose(GObject *object)
{
    NMDeviceIwdP2P        *self = NM_DEVICE_IWD_P2P(object);
    NMDeviceIwdP2PPrivate *priv = NM_DEVICE_IWD_P2P_GET_PRIVATE(object);

    nm_clear_g_source_inst(&priv->peer_dump_source);

    nm_device_iwd_p2p_set_dbus_obj(self, NULL);

    G_OBJECT_CLASS(nm_device_iwd_p2p_parent_class)->dispose(object);
}