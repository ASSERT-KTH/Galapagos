static int setPortTimeouts(csp_usart_fd_t fd) {

    COMMTIMEOUTS timeouts = {0};

    if (!GetCommTimeouts(fd, &timeouts)) {
        csp_log_error("Error gettings current timeout settings, error: %lu", GetLastError());
        return CSP_ERR_INVAL;
    }

    timeouts.ReadIntervalTimeout = 5;
    timeouts.ReadTotalTimeoutMultiplier = 1;
    timeouts.ReadTotalTimeoutConstant = 5;
    timeouts.WriteTotalTimeoutMultiplier = 1;
    timeouts.WriteTotalTimeoutConstant = 5;

    if(!SetCommTimeouts(fd, &timeouts)) {
        csp_log_error("Error setting timeout settings, error: %lu", GetLastError());
        return CSP_ERR_INVAL;
    }

    return CSP_ERR_NONE;
}