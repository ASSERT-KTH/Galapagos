int csp_bin_sem_remove(csp_bin_sem_handle_t * sem) {

    if( !CloseHandle(*sem) ) {
        return CSP_SEMAPHORE_ERROR;
    }
    return CSP_SEMAPHORE_OK;
}