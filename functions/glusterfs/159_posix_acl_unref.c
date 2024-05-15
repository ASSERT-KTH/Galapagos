posix_acl_unref (xlator_t *this, struct posix_acl *acl)
{
        struct posix_acl_conf  *conf = NULL;
        int                     refcnt = 0;

        conf = this->private;

        LOCK(&conf->acl_lock);
        {
                refcnt = --acl->refcnt;
        }
        UNLOCK(&conf->acl_lock);

        if (!refcnt)
                posix_acl_destroy (this, acl);
}