import json
def main():
    projects = ['alsa-lib', 'ffmpeg', 'openssl', 'liboqs', 'libgcrypt', 'libsodium']

    for proj in projects:
        with open(f'perf/{proj}.json') as f:
            data = json.load(f)

            for fn in data.keys():
                if data[fn].get('cycles_nversion'):

                    extra_time = data[fn]['cycles_nversion'] - data[fn]['cycles_baseline']
                    perf_overhead = extra_time / data[fn]['cycles_baseline']
                    data[fn]['perf_overhead'] = perf_overhead
                    data[fn]['norm_perf_overhead'] = perf_overhead / data[fn]['versions']
            
            new_data = data.copy()
            
            for fn in data.keys():
                if data[fn].get('cycles_nversion') == None:
                    del(new_data[fn])


            print( json.dumps(new_data, indent=2))

main()
