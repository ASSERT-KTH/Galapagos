inode_link (inode_t *inode, inode_t *parent, const char *name,
            struct iatt *iatt)
{
        inode_table_t *table = NULL;
        inode_t       *linked_inode = NULL;

        if (!inode) {
                gf_log_callingfn (THIS->name, GF_LOG_WARNING, "inode not found");
                return NULL;
        }

        table = inode->table;

        pthread_mutex_lock (&table->lock);
        {
                linked_inode = __inode_link (inode, parent, name, iatt);

                if (linked_inode)
                        __inode_ref (linked_inode);
        }
        pthread_mutex_unlock (&table->lock);

        inode_table_prune (table);

        return linked_inode;
}