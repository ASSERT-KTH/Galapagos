verto_del(verto_ev *ev)
{
    if (!ev)
        return;

    /* If the event is freed in the callback, we just set a flag so that
     * verto_fire() can actually do the delete when the callback completes.
     *
     * If we don't do this, than verto_fire() will access freed memory. */
    if (ev->depth > 0) {
        ev->deleted = 1;
        return;
    }

    if (ev->onfree)
        ev->onfree(ev->ctx, ev);
    ev->ctx->module->funcs->ctx_del(ev->ctx->ctx, ev, ev->ev);
    remove_ev(&(ev->ctx->events), ev);

    if ((ev->type == VERTO_EV_TYPE_IO) &&
        (ev->flags & VERTO_EV_FLAG_IO_CLOSE_FD) &&
        !(ev->actual & VERTO_EV_FLAG_IO_CLOSE_FD))
        close(ev->option.io.fd);

    vfree(ev);
}