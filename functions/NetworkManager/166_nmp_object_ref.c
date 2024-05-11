nmp_object_ref(const NMPObject *obj)
{
    if (!obj) {
        /* for convenience, allow NULL. */
        return NULL;
    }

    /* ref and unref accept const pointers. NMPObject is supposed to be shared
     * and kept immutable. Disallowing to take/return a reference to a const
     * NMPObject is cumbersome, because callers are precisely expected to
     * keep a ref on the otherwise immutable object. */
    g_return_val_if_fail(NMP_OBJECT_IS_VALID(obj), NULL);
    g_return_val_if_fail(obj->parent._ref_count != NM_OBJ_REF_COUNT_STACKINIT, NULL);

    return (const NMPObject *) nm_dedup_multi_obj_ref((const NMDedupMultiObj *) obj);
}