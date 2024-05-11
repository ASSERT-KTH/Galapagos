static long snd_pcm_shm_action(snd_pcm_t *pcm)
{
	snd_pcm_shm_t *shm = pcm->private_data;
	int err, result;
	char buf[1] = "";
	volatile snd_pcm_shm_ctrl_t *ctrl = shm->ctrl;

	if (ctrl->hw.changed || ctrl->appl.changed)
		return -EBADFD;
	err = write(shm->socket, buf, 1);
	if (err != 1)
		return -EBADFD;
	err = read(shm->socket, buf, 1);
	if (err != 1)
		return -EBADFD;
	if (ctrl->cmd) {
		SNDERR("Server has not done the cmd");
		return -EBADFD;
	}
	result = ctrl->result;
	if (ctrl->hw.changed) {
		err = snd_pcm_shm_new_rbptr(pcm, shm, &pcm->hw, &ctrl->hw);
		if (err < 0)
			return err;
		ctrl->hw.changed = 0;
	}
	if (ctrl->appl.changed) {
		err = snd_pcm_shm_new_rbptr(pcm, shm, &pcm->appl, &ctrl->appl);
		if (err < 0)
			return err;
		ctrl->appl.changed = 0;
	}
	return result;
}