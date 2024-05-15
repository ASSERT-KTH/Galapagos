runner_end (runner_t *runner)
{
        int i = 0;
        int ret = -1;
        char **p = NULL;

        ret = runner_end_reuse (runner);

        if (runner->argv) {
                for (p = runner->argv; *p; p++)
                        GF_FREE (*p);
                GF_FREE (runner->argv);
        }
        for (i = 0; i < 3; i++)
                close (runner->chfd[i]);

        return ret;
}