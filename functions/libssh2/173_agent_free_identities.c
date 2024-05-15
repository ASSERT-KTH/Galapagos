agent_free_identities(LIBSSH2_AGENT *agent)
{
    struct agent_publickey *node;
    struct agent_publickey *next;

    for(node = _libssh2_list_first(&agent->head); node; node = next) {
        next = _libssh2_list_next(&node->node);
        LIBSSH2_FREE(agent->session, node->external.blob);
        LIBSSH2_FREE(agent->session, node->external.comment);
        LIBSSH2_FREE(agent->session, node);
    }
    _libssh2_list_init(&agent->head);
}