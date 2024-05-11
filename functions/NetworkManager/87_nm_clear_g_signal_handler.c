nm_clear_g_signal_handler(gpointer self, gulong *id)
{
    gulong v;

    if (id && (v = *id)) {
        *id = 0;
        g_signal_handler_disconnect(self, v);
        return TRUE;
    }
    return FALSE;
}