nm_clear_g_source(guint *id)
{
    guint v;

    if (id && (v = *id)) {
        *id = 0;
        g_source_remove(v);
        return TRUE;
    }
    return FALSE;
}