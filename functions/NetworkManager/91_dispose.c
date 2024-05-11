dispose(GObject *object)
{
    adsl_cleanup(NM_DEVICE_ADSL(object));

    nm_clear_g_source(&NM_DEVICE_ADSL_GET_PRIVATE(object)->carrier_poll_id);

    G_OBJECT_CLASS(nm_device_adsl_parent_class)->dispose(object);
}