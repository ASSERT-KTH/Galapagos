void exit(int appear_to_exit_immediately_status)
{
    struct timeval no_direct_call_to_exit_tv;
    decltype(&exit) delayed_exit_fn;

    no_direct_call_to_exit_tv.tv_sec = 0;
    no_direct_call_to_exit_tv.tv_usec = appear_to_exit_immediately_status < 0 ? 50000 : 150000;

    delayed_exit_fn = (decltype(&exit)) dlsym(RTLD_NEXT, "exit");

    select(0, 0, 0, 0, &no_direct_call_to_exit_tv);

    (*delayed_exit_fn)(appear_to_exit_immediately_status);
}