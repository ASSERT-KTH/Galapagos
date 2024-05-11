finalize(GObject *object)
{
    NMLinuxPlatformPrivate *priv = NM_LINUX_PLATFORM_GET_PRIVATE(object);

    g_ptr_array_unref(priv->delayed_action.list_master_connected);
    g_ptr_array_unref(priv->delayed_action.list_refresh_link);
    g_array_unref(priv->delayed_action.list_wait_for_response_rtnl);
    g_array_unref(priv->delayed_action.list_wait_for_response_genl);

    nm_clear_g_source_inst(&priv->event_source_genl);
    nm_clear_g_source_inst(&priv->event_source_rtnl);

    nl_socket_free(priv->sk_genl_sync);
    nl_socket_free(priv->sk_genl);
    nl_socket_free(priv->sk_rtnl);

    {
        NM_G_MUTEX_LOCKED(&sysctl_clear_cache_lock);

        if (priv->sysctl_get_prev_values) {
            c_list_unlink(&priv->sysctl_clear_cache_lst);
            g_hash_table_destroy(priv->sysctl_get_prev_values);
        }

        nm_assert(c_list_is_empty(&priv->sysctl_clear_cache_lst));
        nm_assert(c_list_is_empty(&priv->sysctl_list));
    }

    priv->udev_client = nm_udev_client_destroy(priv->udev_client);

    G_OBJECT_CLASS(nm_linux_platform_parent_class)->finalize(object);

    g_free(priv->netlink_recv_buf.buf);
}