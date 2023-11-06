Sorry, the function is already optimised and making it smaller could affect readability while not providing significant performance benefits.

The algorithm performs finite field multiplication with school-book multiplication followed by carry chain propagation. Because addition and subtraction on integers is a cheap operation, this function has been "untwisted" to do fast carry propagations. The implementation does not require conditional jumps and does not require the default x86 C calling conventions.

Another option to change the function would require the use of an architecture-specific implementation. If one used GCC inline assembler for x86, advantage could be taken of the high-latency, high-throughput multiplier, and do much better than one pass of Gröbner basis theory (one multiplication instead of four). However, this change is much bigger and more complex than requested.
