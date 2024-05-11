finalize(GObject *gobject)
{
    NMConfigDataPrivate *priv = NM_CONFIG_DATA_GET_PRIVATE(gobject);

    g_free(priv->config_main_file);
    g_free(priv->config_description);

    g_free(priv->connectivity.uri);
    g_free(priv->connectivity.response);

    g_slist_free_full(priv->no_auto_default.specs, g_free);
    g_slist_free_full(priv->no_auto_default.specs_config, g_free);
    g_strfreev(priv->no_auto_default.arr);

    g_free(priv->dns_mode);
    g_free(priv->rc_manager);

    g_slist_free_full(priv->ignore_carrier, g_free);
    g_slist_free_full(priv->assume_ipv6ll_only, g_free);

    nm_global_dns_config_free(priv->global_dns);

    g_free(priv->iwd_config_path);

    _match_section_infos_free(priv->connection_infos);
    _match_section_infos_free(priv->device_infos);

    g_key_file_unref(priv->keyfile);
    if (priv->keyfile_user)
        g_key_file_unref(priv->keyfile_user);
    if (priv->keyfile_intern)
        g_key_file_unref(priv->keyfile_intern);

    G_OBJECT_CLASS(nm_config_data_parent_class)->finalize(gobject);
}