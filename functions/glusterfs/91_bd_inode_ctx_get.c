bd_inode_ctx_get (inode_t *inode, xlator_t *this, bd_attr_t **ctx)
{
        int       ret     = -1;
        uint64_t  ctx_int = 0;

        GF_VALIDATE_OR_GOTO (this->name, inode, out);
        ret = inode_ctx_get (inode, this, &ctx_int);
        if (ret)
                return ret;
        if (ctx)
                *ctx = (bd_attr_t *) ctx_int;
out:
        return ret;
}