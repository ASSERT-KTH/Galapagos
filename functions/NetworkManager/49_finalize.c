finalize(GObject *object)
{
    NMDevicePrivate *priv = NM_DEVICE_GET_PRIVATE(object);

    nm_clear_pointer(&priv->lldp_neighbors, g_ptr_array_unref);

    g_free(priv->interface);
    g_free(priv->ip_interface);
    g_free(priv->udi);
    g_free(priv->path);
    g_free(priv->driver);
    g_free(priv->driver_version);
    g_free(priv->firmware_version);
    g_free(priv->product);
    g_free(priv->vendor);
    g_free(priv->short_vendor);
    g_free(priv->description);
    g_free(priv->bus_name);
    g_free(priv->type_description);
    g_free(priv->physical_port_id);
    g_free(priv->hw_address);

    nm_clear_pointer(&priv->udev, udev_unref);

    G_OBJECT_CLASS(nm_device_parent_class)->finalize(object);
}