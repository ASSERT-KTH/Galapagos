static int snd_ctl_shm_action(snd_ctl_t *ctl)
{
	snd_ctl_shm_t *shm = ctl->private_data;
	int err;
	char buf[1] = {0};
	volatile snd_ctl_shm_ctrl_t *ctrl = shm->ctrl;
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
	return ctrl->result;
}