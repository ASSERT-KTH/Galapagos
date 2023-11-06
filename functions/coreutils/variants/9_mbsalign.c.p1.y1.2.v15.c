Here are three variants of the original function. The changes are mostly cosmetic that I deemed could hopefully improve readability to some extent.

Variant 1: Moving parts of implicit inline comments to real comments and eliminating some unused brackets.


mbsalign(char const *src, char *dest, size_t dest_size, size_t *width, mbs_align_t align, int flags) {

  // The beginning is the same until
  ...
 
  if (wc_enabled && (conversion || (n_cols > *width))) {

    // We always trunc if width requested short than detected width
    n_cols = *width;

    if (conversion) {
      // convesions may increase size: \t can become \uFFFD.
      src_size = wcstombs(￼nullptr, str_wc, 0) + 1;
    }

    newstr = malloc(src_size);

    // If malloc fails - show fallback rather than just cleanup
    if (newstr == nullptr) { ￼
      goto mbsalign_unibyte;
    }

    str_to_print = newstr;
    n_used_bytes = wcstombs(newstr, str_wc, src_size);
}

mbsalign_unibyte:

  ...

}


Variant 2: Adjusting the gray special string allocation is modified to remove redundancy of else's after goto in 


mbsalign(char const *src, char *dest, size_t dest_size, size_t *width, mbs_align_t align, int flags) {

  // The beginning is essentially is similar until ...

    str_wc = malloc(src_chars * sizeof(wchar_t));

    if (str_wc == nullptr || mbstowcs(str_wc, src, src_chars) != 0) {
      goto ((flags & MBA_UNIBYTE_FALLBACK) ? mbsalign_unibyte : mbsalign_cleanup);
      }
    }
  }

  ...

  free(str_wc =NULL);
  free(newstr =NULL);

  return ret;

}


Variant 3: Merging all clean-up phase to a single point-code-reuse.


mbsalign(char const *src, char *dest, size_t dest_size, size_t *width, mbs_align_t align, int flags) {

  ...

  if (wc_enabled && (conversion || (n_cols > *width))) {
    // We might non-Printables and we require to truncate string

    if (!(newstr = malloc(src_size)) || (n_used_bytes = wcstombs(newstr, str_wc, src_size) != 0)) {
      // Malloc failed of new conversion made ...
      free(str_wc);
      free(newstr);
    }
  }
  

  ...

  }
