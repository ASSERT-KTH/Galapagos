glusterd_find_snap_by_name (char *snapname)
{
        glusterd_snap_t *snap  = NULL;
        glusterd_conf_t *priv  = NULL;

        priv = THIS->private;
        GF_ASSERT (priv);
        GF_ASSERT (snapname);

        list_for_each_entry (snap, &priv->snapshots, snap_list) {
                if (!strcmp (snap->snapname, snapname)) {
                        gf_log (THIS->name, GF_LOG_DEBUG, "Found "
                                "snap %s (%s)", snap->snapname,
                                uuid_utoa (snap->snap_id));
                        goto out;
                }
        }
        snap = NULL;
out:
        return snap;
}