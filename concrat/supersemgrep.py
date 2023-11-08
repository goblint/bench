import os
import re
import csv

# Define the regular expressions for the pthread functions in a dictionary
regex_patterns = {
    'create': r'pthread_create',
    'join': r'pthread_join',
    'join-arrow': r'pthread_join(.*->.*)',
    'join-idx': r'pthread_join(.*\[.*\])',
    'detach': r'pthread_detach',
    'inc': r'.*thread.*\+\+',
    'lock': r'pthread_mutex_lock',
    'lock-arrow': r'pthread_mutex_lock(.*->.*)',
    'lock-idx': r'pthread_mutex_lock(.*\[.*\])'
}

def count_pthread_functions(file_path):
    # Initialize a dictionary to store the counts
    counts = {func: 0 for func in regex_patterns}
    
    # Read the file and count the occurrences
    with open(file_path, 'r') as file:
        content = file.read()
        for func, pattern in regex_patterns.items():
            counts[func] = len(re.findall(pattern, content))
            
    return counts

# Walk through each directory and analyze the C files
def analyze_projects(root_dir):
    results = []
    
    for subdir, dirs, files in os.walk(root_dir):
        for file in files:
            if file == 'main.c':
                file_path = os.path.join(subdir, file)
                project_name = os.path.basename(subdir)
                counts = count_pthread_functions(file_path)
                results.append([project_name] + [counts[func] for func in regex_patterns])

    sorted_results = sorted(results, key=lambda x: x[0])            
    return sorted_results

# Write the results to a CSV file
def write_to_csv(results, output_file):
    with open(output_file, 'w', newline='') as file:
        writer = csv.writer(file)
        # Write header using the keys from regex_patterns
        writer.writerow(['Project Name'] + list(regex_patterns.keys()))
        for row in results:
            writer.writerow(row)

# Define the directory path where the C projects are located
root_directory = '.'  # Replace with the path to your C projects directory
output_csv = 'results.csv'  # Replace with the desired output CSV file path

# Analyze the projects and write the output
project_results = analyze_projects(root_directory)
write_to_csv(project_results, output_csv)

print(f"Analysis complete. Results have been written to {output_csv}")
