marker_local_unref (marker_local_t *local)
{
        int32_t   var = 0;

        if (local == NULL)
                return -1;

        LOCK (&local->lock);
        {
                var = --local->ref;
        }
        UNLOCK (&local->lock);

        if (var != 0)
                goto out;

        loc_wipe (&local->loc);
        loc_wipe (&local->parent_loc);
        if (local->xdata)
                dict_unref (local->xdata);

        if (local->oplocal) {
                marker_local_unref (local->oplocal);
                local->oplocal = NULL;
        }
        mem_put (local);
out:
        return 0;
}