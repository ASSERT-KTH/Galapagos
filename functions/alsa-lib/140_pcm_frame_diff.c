static inline snd_pcm_sframes_t pcm_frame_diff(snd_pcm_uframes_t ptr1,
					       snd_pcm_uframes_t ptr2,
					       snd_pcm_uframes_t boundary)
{
	if (ptr1 < ptr2)
		return ptr1 + (boundary - ptr2);
	else
		return ptr1 - ptr2;
}