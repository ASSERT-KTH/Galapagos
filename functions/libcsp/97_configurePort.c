static int configurePort(csp_usart_fd_t fd, const csp_usart_conf_t * conf) {

    DCB portSettings = {0};
    portSettings.DCBlength = sizeof(portSettings);
    if(!GetCommState(fd, &portSettings) ) {
        csp_log_error("Could not get default settings for open COM port, error: %lu", GetLastError());
        return CSP_ERR_INVAL;
    }
    portSettings.BaudRate = conf->baudrate;
    portSettings.Parity = conf->paritysetting;
    portSettings.StopBits = conf->stopbits;
    portSettings.fParity = conf->checkparity;
    portSettings.fBinary = TRUE;
    portSettings.ByteSize = conf->databits;
    if (!SetCommState(fd, &portSettings)) {
        csp_log_error("Could not configure COM port, error: %lu", GetLastError());
        return CSP_ERR_INVAL;
    }

    return CSP_ERR_NONE;
}