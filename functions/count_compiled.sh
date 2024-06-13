#!/bin/bash


for PROJECT in "alsa-lib" "ffmpeg" "libgcrypt" "liboqs" "libsodium" "openssl"; do
    pushd "../functions/$PROJECT/variants/go"
    ls 0*.bc | wc -l
    ls 1*.bc | wc -l
    ls 2*.bc | wc -l
    ls 3*.bc | wc -l
    ls 4*.bc | wc -l
    popd
done
