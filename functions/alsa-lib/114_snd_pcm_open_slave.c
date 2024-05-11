snd_pcm_open_slave(snd_pcm_t **pcmp, snd_config_t *root,
		   snd_config_t *conf, snd_pcm_stream_t stream,
		   int mode, snd_config_t *parent_conf)
{
	return snd_pcm_open_named_slave(pcmp, NULL, root, conf, stream,
					mode, parent_conf);
}