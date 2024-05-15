krb5_init_context(krb5_context *context)
{
    /*
     * This is rather silly, but should improve our chances of
     * retaining the krb5_brand array in the final linked library,
     * better than a static variable that's unreferenced after
     * optimization, or even a non-static symbol that's not exported
     * from the library nor referenced from anywhere else in the
     * library.
     *
     * If someday we grow an API to actually return the string, we can
     * get rid of this silliness.
     */
    int my_zero = (krb5_brand[0] == 0);

    return krb5_init_context_profile(NULL, my_zero, context);
}