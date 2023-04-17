#!/bin/bash

# Check if two files are provided as arguments
if [ "$#" -ne 2 ]; then
  echo "Usage: $0 file1 file2"
  exit 1
fi

file1="$1"
file2="$2"

# Check if the files exist
if [ ! -f "$file1" ] || [ ! -f "$file2" ]; then
  echo "Error: One or both files do not exist."
  exit 1
fi

# Calculate the number of lines in both files
total_lines=$(cat "$file1" "$file2" | wc -l)

# Calculate the number of differing lines using diff
differing_lines=$(diff -U 0 "$file1" "$file2" | grep -c '^@')

# Calculate the similarity score as a percentage
similarity=$(echo "scale=3.5; (1 - ($differing_lines / $total_lines)) * 100" | bc)

# Print the similarity score
echo "Similarity: $similarity%"


