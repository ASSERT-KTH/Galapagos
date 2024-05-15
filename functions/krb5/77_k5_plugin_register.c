k5_plugin_register(krb5_context context, int interface_id, const char *modname,
                   krb5_plugin_initvt_fn module)
{
    struct plugin_interface *interface = get_interface(context, interface_id);

    if (interface == NULL)
        return EINVAL;

    /* Disallow registering plugins after load.  We may need to reconsider
     * this, but it simplifies the design. */
    if (interface->configured)
        return EINVAL;

    return register_module(context, interface, modname, NULL, module);
}