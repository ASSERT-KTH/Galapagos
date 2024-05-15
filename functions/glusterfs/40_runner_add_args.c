runner_add_args (runner_t *runner, ...)
{
        va_list argp;

        va_start (argp, runner);
        runner_va_add_args (runner, argp);
        va_end (argp);
}