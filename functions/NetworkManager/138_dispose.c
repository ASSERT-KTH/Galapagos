dispose(GObject *object)
{
    NMPowerMonitor *self = NM_POWER_MONITOR(object);

    drop_inhibitor(self, TRUE);

    nm_clear_g_cancellable(&self->cancellable);

    if (self->proxy) {
        nm_clear_g_signal_handler(self->proxy, &self->sig_id_1);
        nm_clear_g_signal_handler(self->proxy, &self->sig_id_2);
        nm_clear_g_signal_handler(self->proxy, &self->sig_id_3);
        g_clear_object(&self->proxy);
    }

    G_OBJECT_CLASS(nm_power_monitor_parent_class)->dispose(object);
}