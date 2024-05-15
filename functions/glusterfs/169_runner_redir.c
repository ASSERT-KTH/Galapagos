runner_redir (runner_t *runner, int fd, int tgt_fd)
{
        GF_ASSERT (fd > 0 && fd < 3);

        if ((fd > 0) && (fd < 3))
                runner->chfd[fd] = (tgt_fd >= 0) ? tgt_fd : -2;
}