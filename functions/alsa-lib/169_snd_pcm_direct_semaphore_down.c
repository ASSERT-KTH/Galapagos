static inline int snd_pcm_direct_semaphore_down(snd_pcm_direct_t *dmix, int sem_num)
{
	struct sembuf op[2] = { { sem_num, 0, 0 }, { sem_num, 1, SEM_UNDO } };
	int err = semop(dmix->semid, op, 2);
	if (err == 0)
		dmix->locked[sem_num]++;
	else if (err == -1)
		err = -errno;
	return err;
}