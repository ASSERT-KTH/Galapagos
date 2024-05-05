int csp_mutex_unlock(csp_mutex_t * mutex) {

    if( !ReleaseMutex(*mutex) ) {
        return CSP_MUTEX_ERROR;
    }
    return CSP_MUTEX_OK;
}