gf_thread_create (pthread_t *thread, const pthread_attr_t *attr,
                  void *(*start_routine)(void *), void *arg)
{
        sigset_t set, old;
        int ret;

        sigemptyset (&set);

        sigfillset (&set);
        sigdelset (&set, SIGSEGV);
        sigdelset (&set, SIGBUS);
        sigdelset (&set, SIGILL);
        sigdelset (&set, SIGSYS);
        sigdelset (&set, SIGFPE);
        sigdelset (&set, SIGABRT);

        pthread_sigmask (SIG_BLOCK, &set, &old);

        ret = pthread_create (thread, attr, start_routine, arg);

        pthread_sigmask (SIG_SETMASK, &old, NULL);

        return ret;
}