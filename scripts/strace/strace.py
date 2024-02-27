from os import path
import subprocess


def diff(trace1, trace2):
    acc = {}
    for k1 in trace1:
        # check if the key is not present in the other dict
        if not trace2.get(k1) != None:
            acc[k1] = trace1[k1]
        # if exists in both compare the number of calls
        elif trace1[k1][0] != trace2[k1][0]:
            acc[k1] = trace1[k1]
    
    for k2 in trace2:
        # check if the key is not present in the other dict
        if not trace2.get(k2) != None:
            acc[k2] = trace2[k2]
        
    return acc 


def parse_line(line):
    vals = line.split()
    return vals[1], vals[0]

def parse_trace(trace_file):
    stats = {}
    with open(trace_file, "r") as f:
        f.readline() # skip the headers
        f.readline() # skip the separator

        line = f.readline()
        while line:
            syscall, count = parse_line(line)
            stats[syscall] = count
            line = f.readline()
    return stats

def strace():
    original_dir = 'test/dir1'
    build_dirs = ['test/dir2', 'test/dir3']
    command = 'result'
    original_trace_file = path.join(original_dir, "trace.txt")
    with open(original_trace_file, "w") as f:
        subprocess.run(["strace", "-c", "-S", "calls", "-U", "calls,syscall", path.join(original_dir, command)], stderr=f)
    original_trace = parse_trace(original_trace_file)

    for dir in build_dirs:
        trace_file = path.join(dir, "trace.txt")
        with open(trace_file, "w") as f:
            subprocess.run(["strace", "-c", "-S", "calls", "-U", "calls,syscall", path.join(original_dir, command)], stderr=f)
        variant_trace = parse_trace(trace_file)

        print(diff(original_trace, variant_trace)) 


if __name__ == "__main__":
    strace()
