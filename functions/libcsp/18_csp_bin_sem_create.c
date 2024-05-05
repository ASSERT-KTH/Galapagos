int csp_bin_sem_create(csp_bin_sem_handle_t * sem) {

    HANDLE semHandle = CreateSemaphore(NULL, 1, 1, NULL);
    if( semHandle == NULL ) {
        return CSP_SEMAPHORE_ERROR;
    }
    *sem = semHandle;
    return CSP_SEMAPHORE_OK;
}