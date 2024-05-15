runner_log (runner_t *runner, const char *dom, gf_loglevel_t lvl,
            const char *msg)
{
        char *buf = NULL;
        size_t len = 0;
        int i = 0;

        if (runner->runerr)
                return;

        for (i = 0;; i++) {
                if (runner->argv[i] == NULL)
                        break;
                len += (strlen (runner->argv[i]) + 1);
        }

        buf = GF_CALLOC (1, len + 1, gf_common_mt_run_logbuf);
        if (!buf) {
                runner->runerr = errno;
                return;
        }
        for (i = 0;; i++) {
                if (runner->argv[i] == NULL)
                        break;
                strcat (buf, runner->argv[i]);
                strcat (buf, " ");
        }
        if (len > 0)
                buf[len - 1] = '\0';

        gf_log_callingfn (dom, lvl, "%s: %s", msg, buf);

        GF_FREE (buf);
}