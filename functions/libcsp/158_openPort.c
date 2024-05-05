static int openPort(const char * device, csp_usart_fd_t * return_fd) {

    *return_fd = CreateFileA(device,
                             GENERIC_READ|GENERIC_WRITE,
                             0,
                             NULL,
                             OPEN_EXISTING,
                             0,
                             NULL);
    if (*return_fd == INVALID_HANDLE_VALUE) {
        csp_log_error("Failed to open port: [%s], error: %lu", device, GetLastError());
        return CSP_ERR_INVAL;
    }

    return CSP_ERR_NONE;
}