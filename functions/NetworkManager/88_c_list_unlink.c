static inline void c_list_unlink(CList *what) {
        /* condition is not needed, but avoids STOREs in fast-path */
        if (c_list_is_linked(what)) {
                c_list_unlink_stale(what);
                *what = (CList)C_LIST_INIT(*what);
        }
}