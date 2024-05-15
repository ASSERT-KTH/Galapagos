inode_unref (inode_t *inode)
{
        inode_table_t *table = NULL;

        if (!inode)
                return NULL;

        table = inode->table;

        pthread_mutex_lock (&table->lock);
        {
                inode = __inode_unref (inode);
        }
        pthread_mutex_unlock (&table->lock);

        inode_table_prune (table);

        return inode;
}