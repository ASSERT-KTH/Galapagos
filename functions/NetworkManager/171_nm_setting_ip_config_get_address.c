nm_setting_ip_config_get_address(NMSettingIPConfig *setting, int idx)
{
    NMSettingIPConfigPrivate *priv;

    g_return_val_if_fail(NM_IS_SETTING_IP_CONFIG(setting), NULL);

    priv = NM_SETTING_IP_CONFIG_GET_PRIVATE(setting);
    g_return_val_if_fail(idx >= 0 && idx < priv->addresses->len, NULL);

    return priv->addresses->pdata[idx];
}