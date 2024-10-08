#!/usr/bin/env bash

FLAG=$1
# build.py requires the PYTHONPATH to be set to the parent folder, since python does not like relative imports
export PYTHONPATH=$(dirname $(dirname $(realpath $0)))

# for each item in the list of projects
for PROJ in "alsa-lib" "ffmpeg" "libgcrypt" "liboqs" "libsodium" "openssl"; do
    echo "[INFO]: Extracting functions from $PROJ"
    if [ "$FLAG" == "--preprocessed" ]; then
        SHADOW=$(python3 build.py $PROJ | tail -n 1)
        EXTRACT_OUTPUT=$(./extract.sh $PROJ --preprocessed $SHADOW)
    elif [ "$FLAG" == "--source" ] || [ -z "$FLAG" ]; then
        EXTRACT_OUTPUT=$(./extract.sh $PROJ)
    else
        echo "Usage: $0 [--source | --preprocessed]"
        exit 1
    fi

    DIR=$(echo "$EXTRACT_OUTPUT" | tail -n 1)
    node generate_function_info.js $PROJ $DIR
    node create_function_files.js $PROJ
    echo "[INFO]: Finished extracting functions from $PROJ"
done