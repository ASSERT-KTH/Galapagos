nm_clear_g_cancellable(GCancellable **cancellable)
{
    GCancellable *v;

    if (cancellable && (v = *cancellable)) {
        *cancellable = NULL;
        g_cancellable_cancel(v);
        g_object_unref(v);
        return TRUE;
    }
    return FALSE;
}