finalize(GObject *object)
{
    NMVpnPluginInfo        *self = NM_VPN_PLUGIN_INFO(object);
    NMVpnPluginInfoPrivate *priv = NM_VPN_PLUGIN_INFO_GET_PRIVATE(self);

    g_free(priv->name);
    g_free(priv->service);
    g_free(priv->auth_dialog);
    g_strfreev(priv->aliases);
    g_free(priv->filename);
    nm_g_hash_table_unref(priv->keys);

    nm_clear_pointer(&priv->keyfile, g_key_file_unref);

    G_OBJECT_CLASS(nm_vpn_plugin_info_parent_class)->finalize(object);
}