runner_add_arg (runner_t *runner, const char *arg)
{
        arg = gf_strdup (arg);
        if (!arg) {
                runner->runerr = errno;
                return;
        }

        runner_insert_arg (runner, (char *)arg);
}