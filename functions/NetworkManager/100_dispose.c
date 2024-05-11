dispose(GObject *object)
{
    NMOvsdb        *self = NM_OVSDB(object);
    NMOvsdbPrivate *priv = NM_OVSDB_GET_PRIVATE(self);

    ovsdb_disconnect(self, FALSE, TRUE);

    nm_assert(c_list_is_empty(&priv->calls_lst_head));

    nm_str_buf_destroy(&priv->input_buf);
    nm_str_buf_destroy(&priv->output_buf);

    g_clear_object(&priv->platform);
    nm_clear_pointer(&priv->bridges, g_hash_table_destroy);
    nm_clear_pointer(&priv->ports, g_hash_table_destroy);
    nm_clear_pointer(&priv->interfaces, g_hash_table_destroy);

    G_OBJECT_CLASS(nm_ovsdb_parent_class)->dispose(object);
}