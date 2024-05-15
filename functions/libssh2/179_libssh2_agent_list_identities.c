libssh2_agent_list_identities(LIBSSH2_AGENT *agent)
{
    memset(&agent->transctx, 0, sizeof(agent->transctx));
    /* Abandon the last fetched identities */
    agent_free_identities(agent);
    return agent_list_identities(agent);
}