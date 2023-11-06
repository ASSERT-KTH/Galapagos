mbsalign (char const *input, char *output, size_t output_size,
          size_t *width, mbs_align_t align_setting, int property)
{
  size_t final_size = SIZE_MAX;
  size_t input_length = strlen (input) + 1;
  char *altered_str = nullptr;
  wchar_t *str_in_wc = nullptr;
  char const *dest_string = input;
  size_t n_wp_units = input_length - 1;
  size_t n_units_occupied = n_wp_units; 
  size_t n_padding_spaces = 0;
  bool replacement = false;
  bool wide_char_conversion_success = false;

  if (!(property & MBA_UNIBYTE_ONLY) && MB_CUR_MAX > 1)
    {
      size_t num_chars_in_input = mbstowcs (nullptr, input, 0);
      if (num_chars_in_input == SIZE_MAX)
        {
          if (property & MBA_UNIBYTE_FALLBACK)
            goto onto_unibyte_conversion;
          else
            goto function_cleanup;
        }
      num_chars_in_input += 1;
      str_in_wc = (wchar_t*) malloc (num_chars_in_input * sizeof (wchar_t));
      if (str_in_wc == nullptr)
        {
          if (property & MBA_UNIBYTE_FALLBACK)
            goto onto_unibyte_conversion;
          else
            goto function_cleanup;
        }
      if (mbstowcs (str_in_wc, input, num_chars_in_input) != 0)
        {
          str_in_wc[num_chars_in_input - 1] = L'\0';
          wide_char_conversion_success = true;
          replacement = modify_wc_if_non_print (str_in_wc);
          n_wp_units = wcswidth (str_in_wc, num_chars_in_input);
        }
    }

  if (wide_char_conversion_success && (replacement || (n_wp_units > *width)))
    {
        if (replacement)
          {
            input_length = wcstombs (nullptr, str_in_wc, 0) + 1;
          }
        altered_str  = (char*)  malloc (input_length);
        if (altered_str == nullptr)
        {
          if (property & MBA_UNIBYTE_FALLBACK)
            goto onto_unibyte_conversion;
          else
            goto function_cleanup;
        }

        dest_string = altered_str;
        n_wp_units = truncate_wc (str_in_wc, *width);
        n_units_occupied = wcstombs (altered_str, str_in_wc, input_length);
    }

onto_unibyte_conversion:

  if (n_wp_units > *width)
    {
      n_wp_units = *width;
      n_units_occupied = n_wp_units;
    }

  if (*width > n_wp_units)
  n_padding_spaces = *width - n_wp_units;

  *width = n_wp_units;

{
    size_t front_padding, rear_padding;
    switch (align_setting)
      {
      case MBS_ALIGN_LEFT:
        front_padding = 0;
        rear_padding = n_padding_spaces;
        break;
      case MBS_ALIGN_RIGHT:
        front_padding = n_padding_spaces;
        rear_padding = 0;
        break;
      case MBS_ALIGN_CENTER:
      default:
        front_padding = n_padding_spaces / 2 + n_padding_spaces % 2;
        rear_padding = n_padding_spaces / 2;
        break;
      }

      if (property & MBA_NO_LEFT_PAD)
        front_padding = 0;
      if (property & MBA_NO_RIGHT_PAD)
        rear_padding = 0;

      if (output_size != 0)
        {
          size_t available_space;
          char *output_end = output + output_size - 1;

          output = pad_alignment (output, output_end, front_padding);

          available_space = output_end - output;
    
          output = mempcpy (output, dest_string, MIN (n_units_occupied , available_space) );

          pad_alignment (output, output_end, rear_padding);
        }

    final_size = n_units_occupied + ((front_padding + rear_padding) * 1 );
}

function_cleanup:
   
  if (newstr) free (newstr);
  if (str_in_wc) free (str_in_wc);

  return final_size;
}