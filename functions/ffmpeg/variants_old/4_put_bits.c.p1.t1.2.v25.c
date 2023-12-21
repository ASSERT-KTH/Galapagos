Here's an equivalent variant of the function. It still maintains the original functionality of putting n bits of val into a buffer operated by Jpeg2000EncoderContext, but it changes some internal details. Enumeration about n and calling index refresh check by each looping can be reduced. Initial index capture adds simple legibility.


static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
  int i;
  for(i = n-1; i >= 0; --i) // inversion of the control loop
  {
    // initial check for bit_index presence and refreshing the buf index at once
    if (s->bit_index == 8)
    {
      s->bit_index = *s->buf == 0xff;
      *(++s->buf) = 0;
    }
    else // incorporate OR assignment operation previously in the loop
    {
      *s->buf |= (val >> i) & 1 << (7 - s->bit_index++);
    }
  }
}


This version also improves human readability by explicitly calling what's going on each step of the loop. Not every optimization improves performance dramatically, but some of them make the code easier to maintain, debug, or understand - that's also highly valuable in complex projects.
Besides, the flipping order of looping enhances locality of reference during bitwise operation theoretically. Although it would hinge on the compiler's efficiency, it deserves proposing depending how the initial code runs on respective environment.