uint32_t csp_crc32_memory(const uint8_t * data, uint32_t length) {
   uint32_t crc;

   crc = 0xFFFFFFFF;
   while (length--)
#ifdef __AVR__
	   crc = pgm_read_dword(&crc_tab[(crc ^ *data++) & 0xFFL]) ^ (crc >> 8);
#else
	   crc = crc_tab[(crc ^ *data++) & 0xFFL] ^ (crc >> 8);
#endif

   return (crc ^ 0xFFFFFFFF);
}