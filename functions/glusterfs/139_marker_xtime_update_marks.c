marker_xtime_update_marks (xlator_t *this, marker_local_t *local)
{
        marker_conf_t *priv = NULL;

        GF_VALIDATE_OR_GOTO ("marker", this, out);
        GF_VALIDATE_OR_GOTO (this->name, local, out);

        priv = this->private;

        if ((local->pid == GF_CLIENT_PID_GSYNCD
             && !(priv->feature_enabled & GF_XTIME_GSYNC_FORCE))
            || (local->pid == GF_CLIENT_PID_DEFRAG))
                goto out;

        marker_gettimeofday (local);

        marker_local_ref (local);

        marker_create_frame (this, local);
out:
        return 0;
}