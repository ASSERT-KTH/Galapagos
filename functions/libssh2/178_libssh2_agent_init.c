libssh2_agent_init(LIBSSH2_SESSION *session)
{
    LIBSSH2_AGENT *agent;

    agent = LIBSSH2_CALLOC(session, sizeof(*agent));
    if(!agent) {
        _libssh2_error(session, LIBSSH2_ERROR_ALLOC,
                       "Unable to allocate space for agent connection");
        return NULL;
    }
    agent->fd = LIBSSH2_INVALID_SOCKET;
    agent->session = session;
    agent->identity_agent_path = NULL;
    _libssh2_list_init(&agent->head);

#ifdef HAVE_WIN32_AGENTS
    agent->pipe = INVALID_HANDLE_VALUE;
    memset(&agent->overlapped, 0, sizeof(OVERLAPPED));
    agent->pending_io = FALSE;
#endif

    return agent;
}