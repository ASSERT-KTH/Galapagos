constructed(GObject *object)
{
    NML3Cfg *self = NM_L3CFG(object);

    nm_assert(NM_IS_NETNS(self->priv.netns));
    nm_assert(self->priv.ifindex > 0);

    self->priv.platform = g_object_ref(nm_netns_get_platform(self->priv.netns));
    nm_assert(NM_IS_PLATFORM(self->priv.platform));

    self->priv.global_tracker =
        nmp_global_tracker_ref(nm_netns_get_global_tracker(self->priv.netns));

    _LOGT("created (netns=" NM_HASH_OBFUSCATE_PTR_FMT ")", NM_HASH_OBFUSCATE_PTR(self->priv.netns));

    G_OBJECT_CLASS(nm_l3cfg_parent_class)->constructed(object);

    _load_link(self, TRUE);
}