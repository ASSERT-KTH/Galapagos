In the Go language, we won't be able to follow the exact syntax used in the C language, and the equivalent implementation would be strongly related to the definitions of methods ("OPEN READER", etc.) being applied towards variable "s" of GetBitContext.
If you could provide a more detailed context of where does this bit of code fits in your project, one could translate the full implementation. In lack of an up to 100% accurate implementation, here's a very rough equivalence of the mentioned function. Notice this code may not compile successfully.

golang
package main

type GetBitContext struct {
    // the structure's fields go here
}

// getBits analogous function in Go
func getBits(s *GetBitContext, n int) (int, error) {
    var err error
    var re, tmp int

    // Open Reader call might go here -
    // which would probably change the readers' position
    // re, err = openReader(s)

    if err != nil {
        return 0, err
    }
    // Checking the assertion
    if (n <= 0) || (n > 25) {
        return 0, errors.New("Assertion failed - Incorrect value of n")
    }

    // Show Ubits, Last Skip Bits, Update Cache equivalents go here
    // They would probably involve reading bits from the file buffer
    // The closest Go has to left shift for uint64 could look like the code given below. Implementation would vary based on 's' properties'
    // tmp = re
    // tmp <<= uint64(n-1)

    if tmp >= int(math.Pow(1, float64(n))) {
        return 0, errors.New("Assertion failed - tmp value is higher than allowed")
    }

    return tmp, nil
}

To achieve an accurate translation you will need to understand in detail what the C implementation is doing - including examining these auxiliary functions and converting those into Go. In particular, note that error handling in C is explicitly built in says with checks for return values, whereas in Go we use multiple return fallues and errors, which isn't directly compatible with the C version.