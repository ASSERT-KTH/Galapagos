static void reg_addrange(regex_t *preg, int lower, int upper)
{
	if (lower > upper) {
		reg_addrange(preg, upper, lower);
	}
	/* Add a range as length, start */
	regc(preg, upper - lower + 1);
	regc(preg, lower);
}