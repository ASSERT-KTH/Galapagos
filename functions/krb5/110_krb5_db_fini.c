krb5_db_fini(krb5_context kcontext)
{
    krb5_error_code status = 0;
    kdb_vftabl *v;

    /* Do nothing if module was never loaded. */
    if (kcontext->dal_handle == NULL)
        return 0;

    v = &kcontext->dal_handle->lib_handle->vftabl;
    status = v->fini_module(kcontext);

    if (status)
        return status;

    return kdb_free_lib_handle(kcontext);
}