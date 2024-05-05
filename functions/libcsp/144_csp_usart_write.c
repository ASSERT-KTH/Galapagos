int csp_usart_write(csp_usart_fd_t fd, const void * data, size_t data_length) {

    DWORD bytesActual;
    if (!WriteFile(fd, data, data_length, &bytesActual, NULL)) {
        return CSP_ERR_TX;
    }
    if( !FlushFileBuffers(fd) ) {
        csp_log_warn("Could not flush write buffer. Code: %lu", GetLastError());
    }
    return (int) bytesActual;
}