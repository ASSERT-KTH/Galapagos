nm_connection_get_connection_type(NMConnection *connection)
{
    NMSettingConnection *s_con;

    s_con = nm_connection_get_setting_connection(connection);
    return s_con ? nm_setting_connection_get_connection_type(s_con) : NULL;
}