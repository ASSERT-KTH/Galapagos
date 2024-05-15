krb5_free_sam_challenge_2(krb5_context ctx, krb5_sam_challenge_2 *sc2)
{
    if (!sc2)
        return;
    krb5_free_sam_challenge_2_contents(ctx, sc2);
    free(sc2);
}