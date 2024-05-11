static inline int snd_pcm_direct_semaphore_up(snd_pcm_direct_t *dmix, int sem_num)
{
	struct sembuf op = { sem_num, -1, SEM_UNDO | IPC_NOWAIT };
	int err = semop(dmix->semid, &op, 1);
	if (err == 0)
		dmix->locked[sem_num]--;
	else if (err == -1)
		err = -errno;
	return err;
}