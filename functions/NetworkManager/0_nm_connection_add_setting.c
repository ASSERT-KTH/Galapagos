nm_connection_add_setting(NMConnection *connection, NMSetting *setting)
{
    g_return_if_fail(NM_IS_CONNECTION(connection));
    g_return_if_fail(NM_IS_SETTING(setting));

    _nm_connection_add_setting(connection, setting);
    _signal_emit_changed(connection);
}