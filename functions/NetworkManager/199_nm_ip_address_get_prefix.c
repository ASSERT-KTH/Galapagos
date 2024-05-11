nm_ip_address_get_prefix(NMIPAddress *address)
{
    g_return_val_if_fail(address != NULL, 0);
    g_return_val_if_fail(address->refcount > 0, 0);

    return address->prefix;
}