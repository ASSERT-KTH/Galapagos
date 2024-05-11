finalize(GObject *object)
{
    NMSettingVlan        *setting = NM_SETTING_VLAN(object);
    NMSettingVlanPrivate *priv    = NM_SETTING_VLAN_GET_PRIVATE(setting);

    g_slist_free_full(priv->ingress_priority_map, g_free);
    g_slist_free_full(priv->egress_priority_map, g_free);

    G_OBJECT_CLASS(nm_setting_vlan_parent_class)->finalize(object);
}