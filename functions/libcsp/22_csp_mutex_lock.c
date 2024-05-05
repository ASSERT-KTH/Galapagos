int csp_mutex_lock(csp_mutex_t * mutex, uint32_t timeout) {

    if(WaitForSingleObject(*mutex, timeout) == WAIT_OBJECT_0) {
            return CSP_MUTEX_OK;
    }
    return CSP_MUTEX_ERROR;
}