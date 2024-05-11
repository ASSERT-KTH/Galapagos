finalize(GObject *object)
{
    NMPlatform        *self = NM_PLATFORM(object);
    NMPlatformPrivate *priv = NM_PLATFORM_GET_PRIVATE(self);
    IP6DadFailedAddr  *addr;

    nm_clear_g_source(&priv->ip4_dev_route_blacklist_check_id);
    nm_clear_g_source(&priv->ip4_dev_route_blacklist_gc_timeout_id);
    nm_clear_pointer(&priv->ip4_dev_route_blacklist_hash, g_hash_table_unref);
    g_clear_object(&self->_netns);
    nm_dedup_multi_index_unref(priv->multi_idx);
    nmp_cache_free(priv->cache);

    while ((addr = c_list_first_entry(&priv->ip6_dadfailed_lst_head, IP6DadFailedAddr, lst))) {
        ip6_dadfailed_addr_free(addr);
    }

    G_OBJECT_CLASS(nm_platform_parent_class)->finalize(object);
}