cli_cmd_sent_status_get (int *status)
{
        int ret = 0;
        GF_ASSERT (status);

        ret = cli_cmd_lock ();
        {
                if (ret == 0)
                        *status = cmd_sent;
        }
        ret = cli_cmd_unlock ();
        return ret;
}