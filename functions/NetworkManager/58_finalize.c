finalize(GObject *object)
{
    NMSettingBondPrivate *priv = NM_SETTING_BOND_GET_PRIVATE(object);

    nm_clear_g_free(&priv->options_idx_cache);
    g_hash_table_destroy(priv->options);

    G_OBJECT_CLASS(nm_setting_bond_parent_class)->finalize(object);
}