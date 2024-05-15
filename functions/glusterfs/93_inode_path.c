inode_path (inode_t *inode, const char *name, char **bufp)
{
        inode_table_t *table = NULL;
        int            ret   = -1;

        if (!inode)
                return -1;

        table = inode->table;

        pthread_mutex_lock (&table->lock);
        {
                ret = __inode_path (inode, name, bufp);
        }
        pthread_mutex_unlock (&table->lock);

        return ret;
}