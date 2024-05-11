finalize(GObject *gobject)
{
    NMConfigPrivate *priv = NM_CONFIG_GET_PRIVATE(gobject);

    state_free(priv->state);

    g_free(priv->config_dir);
    g_free(priv->system_config_dir);
    g_free(priv->no_auto_default_file);
    g_free(priv->intern_config_file);
    g_free(priv->log_level);
    g_free(priv->log_domains);
    g_strfreev(priv->atomic_section_prefixes);
    g_strfreev(priv->warnings);

    _nm_config_cmd_line_options_clear(&priv->cli);

    g_clear_object(&priv->config_data);
    g_clear_object(&priv->config_data_orig);

    G_OBJECT_CLASS(nm_config_parent_class)->finalize(gobject);
}