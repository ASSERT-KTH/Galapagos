nm_ip_address_get_address(NMIPAddress *address)
{
    g_return_val_if_fail(address != NULL, NULL);
    g_return_val_if_fail(address->refcount > 0, NULL);

    return address->address;
}