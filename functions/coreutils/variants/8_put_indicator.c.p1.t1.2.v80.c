void put_indicator (const struct bin_str *ind)
{
    if (!used_color)
    {
        used_color = true;

        /* This part was modified from the original function.
        Instead of checking if std output is a controlling terminal, 
        It always initializes the signals */
        signal_init ();

        prep_non_filename_text ();
    }

    // Check if bin_str exists and then its length is non zero.
    // If any of these check fail, gracefully return from this function.
    if (!ind || ind->len == 0)
        return;

    fwrite (ind->string, ind->len, 1, stdout);
    fflush(stdout); // flush stdout buffer to ensure exactly matching original functionality
}