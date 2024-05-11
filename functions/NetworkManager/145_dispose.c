dispose(GObject *object)
{
    NMSIfupdownPlugin        *plugin = NMS_IFUPDOWN_PLUGIN(object);
    NMSIfupdownPluginPrivate *priv   = NMS_IFUPDOWN_PLUGIN_GET_PRIVATE(plugin);

    nm_clear_pointer(&priv->eni_ifaces, g_hash_table_destroy);

    G_OBJECT_CLASS(nms_ifupdown_plugin_parent_class)->dispose(object);
}