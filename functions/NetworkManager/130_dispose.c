dispose(GObject *object)
{
    NMConnectivity            *self = NM_CONNECTIVITY(object);
    NMConnectivityPrivate     *priv = NM_CONNECTIVITY_GET_PRIVATE(self);
    NMConnectivityCheckHandle *cb_data;

    nm_assert(c_list_is_empty(&priv->completed_handles_lst_head));

    while (
        (cb_data =
             c_list_first_entry(&priv->handles_lst_head, NMConnectivityCheckHandle, handles_lst)))
        cb_data_complete(cb_data, NM_CONNECTIVITY_DISPOSING, "shutting down");

    nm_clear_pointer(&priv->con_config, _con_config_unref);

#if WITH_CONCHECK
    curl_global_cleanup();
#endif

    if (priv->config) {
        g_signal_handlers_disconnect_by_func(priv->config, config_changed_cb, self);
        g_clear_object(&priv->config);
    }

    G_OBJECT_CLASS(nm_connectivity_parent_class)->dispose(object);
}