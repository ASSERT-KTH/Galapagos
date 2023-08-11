uint64_t load_3(const unsigned char *in) 
{
	uint64_t result;
	result = (*((uint64_t*) in)) & 0x00FFFFFF;
	return result;
}