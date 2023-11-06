Variant 1:
The function is silently falling back to `program`'s value when the corresponding node is not found in the `infomap`, and easily print `undefined` values. This can lead to confusion if `program` is expected to always have a corresponding string value.

Let's make this situation clearer by printing a warning when such a case happens.
By adding the following piece of code after `node = map_prog->node;`, we won't change the behaviour, but document it better :

      // Include stdlib.h at the beginning of the file.
      if ((program != sensorless_controller) && (program != map_prog->program))
      {
         printf("Invalid program name: %s\nPlease check it exists in the documentation.\n", program);
      }

Reminder : the whole change inside the function is only 

      if ((program != sensorless_controller) && (program != map_prog->program))
      {
         printf("Invalid program name: %s\nPlease check it exists in the documentation.\n", program);
      }


Variant 2:
An improvement could consist in sorting `infomap` by program names and using a binary search instead of a linear one. The WORST-case complexity of working execution time would pass from O(n) to O(log n).
However, since a binary search algorithm in C is a bit heavier, we chose to not implement it ourselves but use the existing binary search method from stdlib.h.
But as your specifications indicate not changing too much the code, let's keep the complex dichotomous search as a variant, sticking still to the simple searching for programmer's sake. To use less popular methods in commonly reused functions can lead to hardly readable and comprehensible pieces of programming. 

Variant 3:
Printing errors on stderr is a usual good practice, and in this function, error and warnings are output everywhere to stdout. Just changing this will offer various possibilities of processing, espacially allowing software to easily ignore them.
If the stdout printings are replaced by stderr printing, transform for example :

    printf("Report any translation bugs to "
              "<https://translationproject.org/team/>\n"); // Before

To :

    fprintf(stderr, "Report any translation bugs to "
                   "<https://translationproject.org/team/>\n"); // After.

So just replace printf by fprintf and adding stderr as first argument when API differences are printed.
For instance, `printf -> stderr, fprintf`.
Remember here to include stdio.h to use fprintf.