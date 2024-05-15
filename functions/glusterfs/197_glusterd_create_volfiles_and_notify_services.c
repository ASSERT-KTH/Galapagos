glusterd_create_volfiles_and_notify_services (glusterd_volinfo_t *volinfo)
{
        int        ret  = -1;
        xlator_t  *this = NULL;

        this = THIS;

        ret = glusterd_create_volfiles (volinfo);
        if (ret)
                goto out;

        ret = glusterd_fetchspec_notify (this);

out:
        return ret;
}