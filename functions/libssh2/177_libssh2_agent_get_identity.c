libssh2_agent_get_identity(LIBSSH2_AGENT *agent,
                           struct libssh2_agent_publickey **ext,
                           struct libssh2_agent_publickey *oprev)
{
    struct agent_publickey *node;
    if(oprev && oprev->node) {
        /* we have a starting point */
        struct agent_publickey *prev = oprev->node;

        /* get the next node in the list */
        node = _libssh2_list_next(&prev->node);
    }
    else
        node = _libssh2_list_first(&agent->head);

    if(!node)
        /* no (more) node */
        return 1;

    *ext = agent_publickey_to_external(node);

    return 0;
}