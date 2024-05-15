void DebugEvent(char *b,...)
{
    HANDLE h; char *ptbuf[1],buf[MAXBUF_+1];
    va_list marker;

    if (IsDebugLogging()) {
	h = RegisterEventSource(NULL, KFW_LOGON_EVENT_NAME);
        if (h) {
            va_start(marker,b);
            StringCbVPrintf(buf, MAXBUF_+1,b,marker);
            buf[MAXBUF_] = '\0';
            ptbuf[0] = buf;
            ReportEvent(h, EVENTLOG_INFORMATION_TYPE, 0, 0, NULL, 1, 0, (const char **)ptbuf, NULL);
            DeregisterEventSource(h);
            va_end(marker);
        }
    }
}