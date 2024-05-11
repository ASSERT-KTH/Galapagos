finalize(GObject *object)
{
    NMFakePlatformPrivate *priv = NM_FAKE_PLATFORM_GET_PRIVATE(object);
    int                    i;

    g_hash_table_unref(priv->options);
    for (i = 0; i < priv->links->len; i++) {
        NMFakePlatformLink *device = &nm_g_array_index(priv->links, NMFakePlatformLink, i);

        nm_clear_pointer(&device->obj, nmp_object_unref);
    }
    g_array_unref(priv->links);

    G_OBJECT_CLASS(nm_fake_platform_parent_class)->finalize(object);
}