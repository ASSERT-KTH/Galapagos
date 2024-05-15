_libssh2_comp_methods(LIBSSH2_SESSION *session)
{
    if(session->flag.compress)
        return comp_methods;
    else
        return no_comp_methods;
}