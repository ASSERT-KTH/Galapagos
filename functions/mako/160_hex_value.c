static unsigned char hex_value (json_char c)
{
   if (isdigit((unsigned char)c))
      return c - '0';

   switch (c) {
      case 'a': case 'A': return 0x0A;
      case 'b': case 'B': return 0x0B;
      case 'c': case 'C': return 0x0C;
      case 'd': case 'D': return 0x0D;
      case 'e': case 'E': return 0x0E;
      case 'f': case 'F': return 0x0F;
      default: return 0xFF;
   }
}