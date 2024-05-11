finalize(GObject *object)
{
    NMSettingBridgePortPrivate *priv = NM_SETTING_BRIDGE_PORT_GET_PRIVATE(object);

    g_ptr_array_unref(priv->vlans);

    G_OBJECT_CLASS(nm_setting_bridge_port_parent_class)->finalize(object);
}