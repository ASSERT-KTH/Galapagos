import json
import sys

if len(sys.argv) not in (4, 5):
    print("Usage: python compare_ctags.py TMP_1 TMP_2 TARGET [--ignore-path]")
    sys.exit(1)

TMP_1, TMP_2, TARGET = sys.argv[1], sys.argv[2], sys.argv[3]
IGNORE_PATH = len(sys.argv) == 5 and sys.argv[4] == "--ignore-path"

# Step 1: Load and parse temp1.dat
with open(TMP_1, 'r') as f:
    temp_lines = f.readlines()

temp_set = set()
for line in temp_lines:
    obj = json.loads(line.strip())
    temp_set.add((obj['name'], obj['path']) if not IGNORE_PATH else obj['name'])

# Step 2: Load and filter temp2.dat
filtered_lines = []
with open(TMP_2, 'r') as f:
    temp2_lines = f.readlines()

for line in temp2_lines:
    obj = json.loads(line.strip())
    if ((obj['name'], obj['path']) if not IGNORE_PATH else obj['name']) in temp_set:
        filtered_lines.append(line)

# Step 3: Write the filtered lines to a new file
with open(TARGET, 'w') as f:
    f.writelines(filtered_lines)

print(f"Filtered {len(filtered_lines)} lines from {TMP_2} and saved to {TARGET}")
