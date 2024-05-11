dispose(GObject *object)
{
    NMNetns        *self = NM_NETNS(object);
    NMNetnsPrivate *priv = NM_NETNS_GET_PRIVATE(self);

    nm_assert(nm_g_hash_table_size(priv->l3cfgs) == 0);
    nm_assert(c_list_is_empty(&priv->l3cfg_signal_pending_lst_head));
    nm_assert(!priv->shared_ips);
    nm_assert(nm_g_hash_table_size(priv->watcher_idx) == 0);
    nm_assert(nm_g_hash_table_size(priv->watcher_by_tag_idx) == 0);
    nm_assert(nm_g_hash_table_size(priv->watcher_ip_data_idx) == 0);

    nm_clear_pointer(&priv->ecmp_track_by_obj, g_hash_table_destroy);
    nm_clear_pointer(&priv->ecmp_track_by_ecmpid, g_hash_table_destroy);

    nm_clear_pointer(&priv->watcher_idx, g_hash_table_destroy);
    nm_clear_pointer(&priv->watcher_by_tag_idx, g_hash_table_destroy);
    nm_clear_pointer(&priv->watcher_ip_data_idx, g_hash_table_destroy);

    nm_clear_g_source_inst(&priv->signal_pending_idle_source);

    if (priv->platform)
        g_signal_handlers_disconnect_by_data(priv->platform, &priv->_self_signal_user_data);

    g_clear_object(&priv->platform);
    nm_clear_pointer(&priv->l3cfgs, g_hash_table_unref);

    nm_clear_pointer(&priv->global_tracker, nmp_global_tracker_unref);

    G_OBJECT_CLASS(nm_netns_parent_class)->dispose(object);
}