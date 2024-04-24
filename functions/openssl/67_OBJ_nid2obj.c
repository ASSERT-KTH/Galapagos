ASN1_OBJECT *OBJ_nid2obj(int n)
{
    ADDED_OBJ ad, *adp = NULL;
    ASN1_OBJECT ob;

    if (n == NID_undef
        || (n > 0 && n < NUM_NID && nid_objs[n].nid != NID_undef))
        return (ASN1_OBJECT *)&(nid_objs[n]);

    ad.type = ADDED_NID;
    ad.obj = &ob;
    ob.nid = n;
    if (!ossl_obj_read_lock(1)) {
        ERR_raise(ERR_LIB_OBJ, ERR_R_UNABLE_TO_GET_READ_LOCK);
        return NULL;
    }
    if (added != NULL)
        adp = lh_ADDED_OBJ_retrieve(added, &ad);
    ossl_obj_unlock(1);
    if (adp != NULL)
        return adp->obj;

    ERR_raise(ERR_LIB_OBJ, OBJ_R_UNKNOWN_NID);
    return NULL;
}