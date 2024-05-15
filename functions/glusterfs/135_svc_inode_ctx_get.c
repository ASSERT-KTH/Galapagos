svc_inode_ctx_get (xlator_t *this, inode_t *inode, int *inode_type)
{
        int          ret        = -1;

        GF_VALIDATE_OR_GOTO ("snapview-client", this, out);
        GF_VALIDATE_OR_GOTO (this->name, inode, out);

        LOCK (&inode->lock);
        {
                ret = __svc_inode_ctx_get (this, inode, inode_type);
        }
        UNLOCK (&inode->lock);

out:
        return ret;
}