int csp_mutex_remove(csp_mutex_t * mutex) {

    if( !CloseHandle(*mutex) ) {
        return CSP_MUTEX_ERROR;
    }
    return CSP_MUTEX_OK;
}