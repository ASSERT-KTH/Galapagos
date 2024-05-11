void *snd_mixer_sbasic_get_private(const snd_mixer_class_t *class)
{
	class_priv_t *priv = snd_mixer_class_get_private(class);

	if (class == NULL)
		return NULL;
	return priv->private_data;
}