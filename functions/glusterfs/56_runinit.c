runinit (runner_t *runner)
{
        int i = 0;

        runner->argvlen = 64;
        runner->argv = GF_CALLOC (runner->argvlen,
                                  sizeof (*runner->argv),
                                  gf_common_mt_run_argv);
        runner->runerr = runner->argv ? 0 : errno;
        runner->chpid = -1;
        for (i = 0; i < 3; i++) {
                runner->chfd[i] = -1;
                runner->chio[i] = NULL;
        }
}