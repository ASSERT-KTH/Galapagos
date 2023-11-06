Unfortunately, a direct conversion of this C code to Go is not possible due to the differences in error handling, variables scope and memory allocation between the two languages. However, a semantically equivalent function with the same functionality can be created:

go
import (
    "errors"
    "strings"
)

func sodiumHex2bin(inputHexStr string, ignoreStr string) ([]byte, error) {
    outputBin := make([]byte, 0)

    inputLen := len(inputHexStr)
    inputIgnorePatternLen := len(ignoreStr)

    stateTracker := 0
    asciiShiftTracker := byte(0)

    hexCursor := 0
    for hexCursor < inputLen {
        singleHexCharacter := byte(inputHexStr[hexCursor])
        xorNum := singleHexCharacter ^ 48
        limitCheckerNumMinusTen := (xorNum - 10) >> 8
        originalAlpha := (singleHexCharacter &^ 32) - 55
        limitCheckerAlpha := ((originalAlpha - 10) ^ (originalAlpha - 16)) >> 8
        
        stateTest := (limitCheckerNumMinusTen | limitCheckerAlpha) == 0

        // check ignore    
        if inputIgnorePatternLen > 0 && stateTracker == 0 && stateTest {
            isHexIgnored := strings.IndexByte(ignoreStr, singleHexCharacter) > -1
            if isHexIgnored {
                hexCursor++
                continue
            }
        }

        if stateTest {
            err := errors.New("input data not hexadecimal: contains character that does not belong to hex charset")
            return nil, err
        }
        
        if stateTracker == 0 {
            asciiShiftTracker = limitCheckerNumMinusTen & xorNum | limitCheckerAlpha & originalAlpha
            asciiShiftTracker *= 16
        } else {
            appendThisByte := asciiShiftTracker | (limitCheckerNumMinusTen & xorNum | limitCheckerAlpha & originalAlpha)
            outputBin = append(outputBin, appendThisByte)
        }
        stateTracker = (stateTracker + 1) % 2
        hexCursor++
    }

    if stateTracker == 1 {
        err := errors.New("input data not a complete hexadecimal: contains incomplete tuple of two characters that can make up to one byte of data")
        hexCursor--
        return outputBin[:hexCursor], err
    }

    return outputBin, nil
}


In this equivalent Go function, `sodiumHex2bin` receives input ‍`inputHexStr` is the hexadecimal string to convert, and `ignoreStr` if some hexadecimal values should be excluded. This routine transforms a hexadecimal representation string into binary and returns the results as a string `([]byte)` with one character equal to one byte. The function demonstrates equivalent functionality even though not all incidental side-effects of constraints/conditions/variables/error-messages have been adhered due to language differences.

Please remember in Go, Error-handling is idiomatic contrast from c's errno for error handling. Here, we used errors returning package `errors` for error notification. Sometimes conversion can't be done bitwise identical due to language differences.