Here is a variant of the original function that performs the same operations although in slightly different approach.


uint64_t load_3(const unsigned char *in)
{
    return ((uint64_t)in[0]) | (((uint64_t)in[1]) << 8) | (((uint64_t)in[2]) << 16);
}

In this variant, the intermediate results are not stored in `result`, but as expression in the return statement. Moreover, no assignments are used to modify `result`. 

The bitwise OR operations provide the same result as in the reference implementation due to the commutative nature of the operation. Because it doesn't use a `result` variable, it reduces the memory footprint.