gf_store_unlink_tmppath (gf_store_handle_t *shandle)
{
        int32_t         ret = -1;
        char            tmppath[PATH_MAX] = {0,};

        GF_VALIDATE_OR_GOTO ("store", shandle, out);
        GF_VALIDATE_OR_GOTO ("store", shandle->path, out);

        snprintf (tmppath, sizeof (tmppath), "%s.tmp", shandle->path);
        ret = unlink (tmppath);
        if (ret && (errno != ENOENT)) {
                gf_log ("", GF_LOG_ERROR, "Failed to mv %s to %s, error: %s",
                        tmppath, shandle->path, strerror (errno));
        } else {
                ret = 0;
        }
out:
        if (shandle && shandle->tmp_fd >= 0) {
                close (shandle->tmp_fd);
                shandle->tmp_fd = -1;
        }
        return ret;
}