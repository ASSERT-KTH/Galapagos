dispose(GObject *object)
{
    NMPlatform             *platform = NM_PLATFORM(object);
    NMLinuxPlatformPrivate *priv     = NM_LINUX_PLATFORM_GET_PRIVATE(platform);

    _LOGD("dispose");

    delayed_action_wait_for_nl_response_complete_all(platform,
                                                     NMP_NETLINK_GENERIC,
                                                     WAIT_FOR_NL_RESPONSE_RESULT_FAILED_DISPOSING);

    delayed_action_wait_for_nl_response_complete_all(platform,
                                                     NMP_NETLINK_ROUTE,
                                                     WAIT_FOR_NL_RESPONSE_RESULT_FAILED_DISPOSING);

    priv->delayed_action.flags = DELAYED_ACTION_TYPE_NONE;
    g_ptr_array_set_size(priv->delayed_action.list_master_connected, 0);
    g_ptr_array_set_size(priv->delayed_action.list_refresh_link, 0);

    G_OBJECT_CLASS(nm_linux_platform_parent_class)->dispose(object);
}