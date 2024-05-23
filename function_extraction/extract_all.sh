#!/usr/bin/env bash

FLAG=$1
SELECTED_FUNCTIONS="$(pwd)/function-picks.json"

# build.py requires the PYTHONPATH to be set to the parent folder, since python does not like relative imports
export PYTHONPATH=$(dirname $(dirname $(realpath $0)))

# for each item in the list of projects
# for PROJ in "alsa-lib" "ffmpeg" "libgcrypt" "liboqs" "libsodium" "openssl"; do
# TODO: there seems to be an issue with alsa-lib? like a symlink for alsa/ inside include/, which is recursive
for PROJ in "ffmpeg"; do
    if [ "$FLAG" == "--preprocessed" ]; then
        SHADOW=$(python3 build.py $PROJ | tail -n 1)
        ./extract.sh $PROJ --preprocessed $SHADOW
        node generate_function_info.js $PROJ --preprocessed
    elif [ "$FLAG" == "--source" ] || [ -z "$FLAG" ]; then
        ./extract.sh $PROJ
        node generate_function_info.js $PROJ
    else
        echo "Usage: $0 [--source | --preprocessed]"
        exit 1
    fi

    node create_function_files.js $PROJ
done