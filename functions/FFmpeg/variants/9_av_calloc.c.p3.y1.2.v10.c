func avCalloc(nmemb uintptr, size uintptr) interface{} {
    result := nmemb * size

    // Avoid integer overflow
    if nmemb != 0 && result/nmemb != size {
        return nil
    }

    return avMallocz(result)
}