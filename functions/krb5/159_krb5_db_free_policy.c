krb5_db_free_policy(krb5_context kcontext, osa_policy_ent_t policy)
{
    if (policy == NULL)
        return;
    free(policy->name);
    free(policy->allowed_keysalts);
    free_tl_data(policy->tl_data);
    free(policy);
}