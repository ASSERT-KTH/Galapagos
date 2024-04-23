addtok (struct dfa *dfa, token t)
{
  if (dfa->localeinfo.multibyte && t == MBCSET)
    {
      bool need_or = false;

      /* Extract wide characters into alternations for better performance.
         This does not require UTF-8.  */
      for (idx_t i = 0; i < dfa->lex.brack.nchars; i++)
        {
          addtok_wc (dfa, dfa->lex.brack.chars[i]);
          if (need_or)
            addtok (dfa, OR);
          need_or = true;
        }
      dfa->lex.brack.nchars = 0;

      /* Wide characters have been handled above, so it is possible
         that the set is empty now.  Do nothing in that case.  */
      if (dfa->lex.brack.cset != -1)
        {
          addtok (dfa, CSET + dfa->lex.brack.cset);
          if (need_or)
            addtok (dfa, OR);
        }
    }
  else
    {
      addtok_mb (dfa, t, 3);
    }
}