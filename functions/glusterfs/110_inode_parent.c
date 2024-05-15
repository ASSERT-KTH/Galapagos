inode_parent (inode_t *inode, uuid_t pargfid, const char *name)
{
        inode_t       *parent = NULL;
        inode_table_t *table = NULL;
        dentry_t      *dentry = NULL;

        if (!inode) {
                gf_log_callingfn (THIS->name, GF_LOG_WARNING, "inode not found");
                return NULL;
        }

        table = inode->table;

        pthread_mutex_lock (&table->lock);
        {
                if (pargfid && !uuid_is_null (pargfid) && name) {
                        dentry = __dentry_search_for_inode (inode, pargfid, name);
                } else {
                        dentry = __dentry_search_arbit (inode);
                }

                if (dentry)
                        parent = dentry->parent;

                if (parent)
                        __inode_ref (parent);
        }
        pthread_mutex_unlock (&table->lock);

        return parent;
}