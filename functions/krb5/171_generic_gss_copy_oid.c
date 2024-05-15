generic_gss_copy_oid(OM_uint32 *minor_status,
                     const gss_OID_desc * const oid,
                     gss_OID *new_oid)
{
    gss_OID         p;

    *minor_status = 0;

    p = (gss_OID) malloc(sizeof(gss_OID_desc));
    if (!p) {
        *minor_status = ENOMEM;
        return GSS_S_FAILURE;
    }
    p->length = oid->length;
    p->elements = malloc(p->length);
    if (!p->elements) {
        free(p);
        return GSS_S_FAILURE;
    }
    memcpy(p->elements, oid->elements, p->length);
    *new_oid = p;
    return(GSS_S_COMPLETE);
}