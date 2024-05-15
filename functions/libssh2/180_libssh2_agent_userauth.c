libssh2_agent_userauth(LIBSSH2_AGENT *agent,
                       const char *username,
                       struct libssh2_agent_publickey *identity)
{
    void *abstract = agent;
    int rc;

    if(agent->session->userauth_pblc_state == libssh2_NB_state_idle) {
        memset(&agent->transctx, 0, sizeof(agent->transctx));
        agent->identity = identity->node;
    }

    BLOCK_ADJUST(rc, agent->session,
                 _libssh2_userauth_publickey(agent->session, username,
                                             strlen(username),
                                             identity->blob,
                                             identity->blob_len,
                                             agent_sign,
                                             &abstract));
    return rc;
}