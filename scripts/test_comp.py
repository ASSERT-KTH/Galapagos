from generate_c import pipeline


if __name__ == '__main__':
    hashes_source = set()
    hashes_target = set()
    hash_per_file = { }
    COUNT = 0
    for i in range(1, 20):
        _, hsh, hshsource = pipeline(f"rosetta_codes/quicksort.v{i}.c")
        if hsh is not None:
            hashes_source.add(hshsource)
            hashes_target.add(hsh)
            COUNT += 1

    print(len(hashes_source), len(hashes_target), COUNT)