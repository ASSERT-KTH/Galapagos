int snd_card_next(int *rcard)
{
	int card;
	
	if (rcard == NULL)
		return -EINVAL;
	card = *rcard;
	card = card < 0 ? 0 : card + 1;
	for (; card < SND_MAX_CARDS; card++) {
		if (snd_card_load(card)) {
			*rcard = card;
			return 0;
		}
	}
	*rcard = -1;
	return 0;
}