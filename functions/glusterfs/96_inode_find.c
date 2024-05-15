inode_find (inode_table_t *table, uuid_t gfid)
{
        inode_t   *inode = NULL;

        if (!table) {
                gf_log_callingfn (THIS->name, GF_LOG_WARNING, "table not found");
                return NULL;
        }

        pthread_mutex_lock (&table->lock);
        {
                inode = __inode_find (table, gfid);
                if (inode)
                        __inode_ref (inode);
        }
        pthread_mutex_unlock (&table->lock);

        return inode;
}