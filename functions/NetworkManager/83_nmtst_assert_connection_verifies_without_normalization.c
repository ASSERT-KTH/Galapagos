nmtst_assert_connection_verifies_without_normalization(NMConnection *con)
{
    /* assert that the connection verifies and does not need any normalization */
    GError                       *error = NULL;
    gboolean                      success;
    gboolean                      was_modified = FALSE;
    gs_unref_object NMConnection *clone        = NULL;

    clone = nmtst_clone_connection(con);

    nmtst_assert_connection_verifies(con);

    success = nm_connection_normalize(clone, NULL, &was_modified, &error);
    g_assert_no_error(error);
    g_assert(success);
    nmtst_assert_connection_equals(con, FALSE, clone, FALSE);
    g_assert(!was_modified);
}