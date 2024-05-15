glusterd_volume_brickinfo_get_by_brick (char *brick,
                                        glusterd_volinfo_t *volinfo,
                                        glusterd_brickinfo_t **brickinfo)
{
        int32_t                 ret = -1;
        glusterd_brickinfo_t    *tmp_brickinfo = NULL;

        GF_ASSERT (brick);
        GF_ASSERT (volinfo);

        ret = glusterd_brickinfo_new_from_brick (brick, &tmp_brickinfo);
        if (ret)
                goto out;

        ret = glusterd_volume_brickinfo_get (NULL, tmp_brickinfo->hostname,
                                             tmp_brickinfo->path, volinfo,
                                             brickinfo);
        (void) glusterd_brickinfo_delete (tmp_brickinfo);
out:
        gf_log ("", GF_LOG_DEBUG, "Returning %d", ret);
        return ret;
}