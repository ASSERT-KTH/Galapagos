dispose(GObject *object)
{
    NMKeepAlive *self = NM_KEEP_ALIVE(object);

    nm_assert(!NM_KEEP_ALIVE_GET_PRIVATE(self)->owner);

    /* disarm also happens to free all resources. */
    nm_keep_alive_disarm(self);
}