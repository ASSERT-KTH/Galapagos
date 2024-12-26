import subprocess

def main():
    projects = ['alsa-lib', 'ffmpeg', 'openssl', 'liboqs', 'libgcrypt', 'libsodium']

    for proj in projects:
        args = [
            'python',
            'template_original_functions_bench.py',
            'c',
            proj]
        print(args)
        subprocess.check_output(args)
main()
