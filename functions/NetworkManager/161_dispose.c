dispose(GObject *object)
{
    NMCSProviderEC2 *self = NMCS_PROVIDER_EC2(object);

    nm_clear_g_free(&self->token);

    G_OBJECT_CLASS(nmcs_provider_ec2_parent_class)->dispose(object);
}