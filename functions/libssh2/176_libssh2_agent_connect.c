libssh2_agent_connect(LIBSSH2_AGENT *agent)
{
    int i, rc = -1;
    for(i = 0; supported_backends[i].name; i++) {
        agent->ops = supported_backends[i].ops;
        rc = (agent->ops->connect)(agent);
        if(!rc)
            return 0;
    }
    return rc;
}