nmtst_assert_connection_verifies(NMConnection *con)
{
    /* assert that the connection does verify, it might be normaliziable or not */
    GError  *error = NULL;
    gboolean success;

    g_assert(NM_IS_CONNECTION(con));

    success = nm_connection_verify(con, &error);
    g_assert_no_error(error);
    g_assert(success);
}