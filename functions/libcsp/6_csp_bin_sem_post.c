int csp_bin_sem_post(csp_bin_sem_handle_t * sem) {

    if( !ReleaseSemaphore(*sem, 1, NULL) ) {
        return CSP_SEMAPHORE_ERROR;
    }
    return CSP_SEMAPHORE_OK;
}