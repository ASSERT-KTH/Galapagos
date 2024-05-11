dispose(GObject *object)
{
#if NM_MORE_ASSERTS
    g_signal_handlers_disconnect_by_data(object,
                                         (gpointer) &_nm_assert_connection_unchanging_user_data);
#endif

    _nm_connection_private_clear(_NM_SIMPLE_CONNECTION_GET_CONNECTION_PRIVATE(object));

    G_OBJECT_CLASS(nm_simple_connection_parent_class)->dispose(object);
}