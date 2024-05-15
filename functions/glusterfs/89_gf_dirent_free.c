gf_dirent_free (gf_dirent_t *entries)
{
        gf_dirent_t *entry = NULL;
        gf_dirent_t *tmp = NULL;

        if (!entries)
                return;

        if (list_empty (&entries->list))
                return;

        list_for_each_entry_safe (entry, tmp, &entries->list, list) {
                if (entry->dict)
                        dict_unref (entry->dict);
                if (entry->inode)
                        inode_unref (entry->inode);

                list_del (&entry->list);
                GF_FREE (entry);
        }
}