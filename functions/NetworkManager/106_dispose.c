dispose(GObject *object)
{
    NMDeviceWifi        *self = NM_DEVICE_WIFI(object);
    NMDeviceWifiPrivate *priv = NM_DEVICE_WIFI_GET_PRIVATE(self);

    nm_assert(c_list_is_empty(&priv->scanning_prohibited_lst_head));

    nm_clear_g_source(&priv->periodic_update_id);
    nm_clear_g_source_inst(&priv->roam_supplicant_wait_source);

    wifi_secrets_cancel(self);

    cleanup_association_attempt(self, TRUE);
    supplicant_interface_release(self);
    cleanup_supplicant_failures(self);

    g_clear_object(&priv->sup_mgr);

    remove_all_aps(self);

    if (priv->p2p_device) {
        /* Destroy the P2P device. */
        g_object_remove_weak_pointer(G_OBJECT(priv->p2p_device), (gpointer *) &priv->p2p_device);
        nm_device_wifi_p2p_remove(g_steal_pointer(&priv->p2p_device));
    }

    G_OBJECT_CLASS(nm_device_wifi_parent_class)->dispose(object);
}