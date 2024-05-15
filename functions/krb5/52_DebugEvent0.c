void DebugEvent0(char *a)
{
    HANDLE h; char *ptbuf[1];

    if (IsDebugLogging()) {
	h = RegisterEventSource(NULL, KFW_LOGON_EVENT_NAME);
	if (h) {
            ptbuf[0] = a;
            ReportEvent(h, EVENTLOG_INFORMATION_TYPE, 0, 0, NULL, 1, 0, (const char **)ptbuf, NULL);
            DeregisterEventSource(h);
        }
    }
}