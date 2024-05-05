int csp_bin_sem_wait(csp_bin_sem_handle_t * sem, uint32_t timeout) {

    if( WaitForSingleObject(*sem, timeout) == WAIT_OBJECT_0 ) {
            return CSP_SEMAPHORE_OK;
    }
    return CSP_SEMAPHORE_ERROR;
}