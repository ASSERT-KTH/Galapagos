int csp_mutex_create(csp_mutex_t * mutex) {

    HANDLE mutexHandle = CreateMutex(NULL, FALSE, FALSE);
    if( mutexHandle == NULL ) {
        return CSP_MUTEX_ERROR;
    }
    *mutex = mutexHandle;
    return CSP_MUTEX_OK;
}