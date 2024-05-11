nm_setting_ip_config_add_address(NMSettingIPConfig *setting, NMIPAddress *address)
{
    NMSettingIPConfigPrivate *priv;
    guint                     i;

    g_return_val_if_fail(NM_IS_SETTING_IP_CONFIG(setting), FALSE);
    g_return_val_if_fail(address != NULL, FALSE);
    g_return_val_if_fail(address->family == NM_SETTING_IP_CONFIG_GET_ADDR_FAMILY(setting), FALSE);

    priv = NM_SETTING_IP_CONFIG_GET_PRIVATE(setting);
    for (i = 0; i < priv->addresses->len; i++) {
        if (nm_ip_address_equal(priv->addresses->pdata[i], address))
            return FALSE;
    }

    g_ptr_array_add(priv->addresses, nm_ip_address_dup(address));

    _notify(setting, PROP_ADDRESSES);
    return TRUE;
}