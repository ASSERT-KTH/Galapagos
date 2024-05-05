int csp_bin_sem_post_isr(csp_bin_sem_handle_t * sem, CSP_BASE_TYPE * task_woken) {

    if( task_woken != NULL ) {
        *task_woken = 0;
    }
    return csp_bin_sem_post(sem);
}