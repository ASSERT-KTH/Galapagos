cli_cmd_broadcast_response (int32_t status)
{

        pthread_mutex_lock (&cond_mutex);
        {
                if (!cmd_sent)
                        goto out;
                cmd_done = 1;
                cli_op_ret = status;
                pthread_cond_broadcast (&cond);
        }


out:
        pthread_mutex_unlock (&cond_mutex);
        return 0;
}