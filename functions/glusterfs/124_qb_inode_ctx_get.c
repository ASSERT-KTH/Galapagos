qb_inode_ctx_get (xlator_t *this, inode_t *inode)
{
        qb_inode_t *qb_inode = NULL;

        LOCK (&inode->lock);
        {
                qb_inode = __qb_inode_ctx_get (this, inode);
        }
        UNLOCK (&inode->lock);

        return qb_inode;
}