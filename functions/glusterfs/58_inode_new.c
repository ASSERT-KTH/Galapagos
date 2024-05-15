inode_new (inode_table_t *table)
{
        inode_t *inode = NULL;

        if (!table) {
                gf_log_callingfn (THIS->name, GF_LOG_WARNING, "inode not found");
                return NULL;
        }

        pthread_mutex_lock (&table->lock);
        {
                inode = __inode_create (table);
                if (inode != NULL) {
                        __inode_ref (inode);
                }
        }
        pthread_mutex_unlock (&table->lock);

        return inode;
}