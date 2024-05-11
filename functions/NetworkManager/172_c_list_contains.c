static inline _Bool c_list_contains(const CList *list, const CList *what) {
        const CList *iter;

        c_list_for_each(iter, list)
                if (what == iter)
                        return 1;

        return what == list;
}