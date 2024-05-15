get_vftabl(krb5_context kcontext, kdb_vftabl **vftabl_ptr)
{
    krb5_error_code status;

    *vftabl_ptr = NULL;
    if (kcontext->dal_handle == NULL) {
        status = krb5_db_setup_lib_handle(kcontext);
        if (status)
            return status;
    }
    *vftabl_ptr = &kcontext->dal_handle->lib_handle->vftabl;
    return 0;
}