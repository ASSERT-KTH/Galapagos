
# for each item in the list of functions
for FUN in "openssl"; do
    # run the function extraction script
    ./extract.sh $FUN
    node find_top.js $FUN
    node create_function_files.js $FUN
done