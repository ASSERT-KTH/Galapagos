import json
import subprocess
import math

def print_eq_count():
    with open('eq_variants.json', 'r') as f:
        eq = json.load(f)

        projects = eq.keys()

        for proj in projects:
            functions = eq[proj].keys()

            for fn in functions:
                for lang in ['c', 'go']:
                    versions = eq[proj][fn][lang]
                    print(proj, fn, lang, len(versions))

def count_total_eq():
    with open('eq_variants.json', 'r') as f:
        eq = json.load(f)

        projects = eq.keys()

        for lang in ['c', 'go']:
            total_eq = 0
            for proj in projects:
                functions = eq[proj].keys()

                for fn in functions:
                    versions = eq[proj][fn][lang]
                    total_eq += len(versions)

            print(lang, total_eq, total_eq/300.0)

def get_stdev():
    with open('eq_variants.json', 'r') as f:
        eq = json.load(f)

        projects = eq.keys()

        for lang in ['c', 'go']:
            total_eq = 0
            for proj in projects:
                functions = eq[proj].keys()

                for fn in functions:
                    versions = eq[proj][fn][lang]
                    total_eq += len(versions)
            avg = total_eq/30
        
            variance = 0
            for proj in projects:
                functions = eq[proj].keys()

                for fn in functions:
                    variance += (len(versions) - avg) ** 2

            print(avg, variance, math.sqrt(variance))


def get_percentiles():
    with open('eq_variants.json', 'r') as f:
        eq = json.load(f)

        projects = eq.keys()

        for lang in ['c', 'go']:
            samples = []
            for proj in projects:
                functions = eq[proj].keys()

                for fn in functions:
                    versions = eq[proj][fn][lang]
                    samples.append(len(versions))


            for i in range(6):
                samples.append(0)
            
            samples = sorted(samples)
            print(samples)

            p25, p50, p75 = int(30*(0.25)), int(30*(0.5)), int(30*(0.75))

            print(samples[p25], samples[p50], samples[p75])

print_eq_count()
#count_total_eq()
#get_percentiles()
