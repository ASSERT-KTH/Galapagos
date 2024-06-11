static unsigned int iec958_parity(unsigned int data)
{
	unsigned int parity;
	int bit;

	data >>= 4;
	parity = 0;
	for (bit = 4; bit <= 30; bit++) {
		if (data & 1)
			parity++;
		data >>= 1;
	}
	return (parity & 1);
}
