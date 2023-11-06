/*** Variation 1 ***/
void sodium_free(void* p)
{
    unsigned char *unprotectedPointer, *basePointer, *canaryPointer;
    size_t fullSize, nonProtectedSize;

    if (!p) 
        return;

    canaryPointer = (unsigned char*)p - sizeof canary;
    unprotectedPointer = _userPointerFromUnprotectedPointer(p);
    basePointer = unprotectedPointer - (page_size * 2);
    
    memcpy(&nonProtectedSize, basePointer, sizeof(nonProtectedSize));

    fullSize = (page_size * 3) + nonProtectedSize;

    _readWriteProtection(basePointer, fullSize);

    if (compareUnprotectedMemory(canaryPointer, canary, sizeof(canary)) != 0)
        _boundExtra();
    # ifndef PAGE_PROINDEX_TECTNOTAVA_LESSER
        if (compareUnprotectedMemory(unprotectedPointer + nonProtectedSize, canary,
                          sizeof(canary)) != 0) 
            _boundExtra();

    # endif
    (void) memoryUnlockProtectedData(unprotectedPointer, nonProtectedSize);
    
    alignFreeMemory(basePointer, fullSize);
} 

/*** Variation 2 ***/
void sodium_free(void* par)
{  
    unsigned char *pointer2ndLayer, *pointer0Layer, *pointer1stLayer;
    size_t aggregateSize, size1Layer;
    
    if (!par) 
        return;

    pointer1stLayer = ((unsigned char*)par)-(sizeof canary);

    pointer2ndLayer = detached_pointer_from_protected_pointer(par);

    pointer0Layer = pointer2ndLayer - (2*page_size);

    memcpy(&size1Layer, pointer0Layer, sizeof(size1Layer));

    aggregateSize = ((3*page_size) + size1Layer);

    allow_readwrite(pointer0Layer, aggregateSize);
    if (sodium_check_memory(pointer1stLayer, canary, sizeof(canary)) != 0)
                                        on_overflow();

    # ifndef HAVE_SAFE_PAGE
        if (sodium_check_memory(pointer2ndLayer + size1Layer, canary, sizeof(canary)) != 0) 
            on_overflow();
    # endif 

    (void) release_locked_memory(pointer2ndLayer, size1Layer);

    memory_to_be_freed_is_aligned(pointer0Layer, aggregateSize);
}

    
ASSISTANT******/
