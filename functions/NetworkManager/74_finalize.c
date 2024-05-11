finalize(GObject *object)
{
    NMSettingWireGuardPrivate *priv = NM_SETTING_WIREGUARD_GET_PRIVATE(object);

    _peers_clear(priv);
    g_ptr_array_unref(priv->peers_arr);
    g_hash_table_unref(priv->peers_hash);

    G_OBJECT_CLASS(nm_setting_wireguard_parent_class)->finalize(object);
}