finalize(GObject *object)
{
#if SESSION_TRACKING_XLOGIND
    st_sd_finalize(NM_SESSION_MONITOR(object));
#endif

#if SESSION_TRACKING_CONSOLEKIT
    ck_finalize(NM_SESSION_MONITOR(object));
#endif

    G_OBJECT_CLASS(nm_session_monitor_parent_class)->finalize(object);
}