#!/usr/bin/env bash

FLAG=$1
SELECTED_FUNCTIONS="$(pwd)/function-picks.json"

# build.py requires the PYTHONPATH to be set to the parent folder, since python does not like relative imports
export PYTHONPATH=$(dirname $(dirname $(realpath $0)))

# for each item in the list of projects
# for PROJ in "alsa-lib" "ffmpeg" "libgcrypt" "liboqs" "libsodium" "openssl"; do
for PROJ in "openssl"; do
    # if FLAG is --preprocessed, we must build the projects w/ save-temps
    # TODO: remove inline stuff!!
    # run the build script

    if [ "$FLAG" == "--preprocessed" ]; then
        SHADOW=$(python3 build.py $PROJ | tail -n 1)
        # run the function extraction script
        ./extract.sh $PROJ --preprocessed $SHADOW
    elif [ "$FLAG" == "--source" ] || [ -z "$FLAG" ]; then
        # run the function extraction script
        ./extract.sh $PROJ
    else
        echo "Usage: $0 [--source | --preprocessed]"
        exit 1
    fi

    node generate_function_info.js $PROJ
    node create_function_files.js $PROJ
done