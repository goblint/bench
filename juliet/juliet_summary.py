import os
import re
import subprocess
import sys
import urllib.request
import zipfile

# Used to access Juliet Suite or to confirm its existence in the current dir
juliet_url = 'https://samate.nist.gov/SRD/testsuites/juliet/Juliet_Test_Suite_v1.3_for_C_Cpp.zip'
juliet_path = 'C/testcases'

# Checking if the testcases path exists, if not the script will download the Juliet Suite
if not os.path.exists(juliet_path):
	os.system('echo "DOWNLOADING JULIET SUITE FROM: "' + juliet_url)
	try:
		zip_path, _ = urllib.request.urlretrieve(juliet_url)
		with zipfile.ZipFile(zip_path, "r") as f:
			f.extractall()	
	except urllib.error.HTTPError:
		os.system('echo "FAILURE: Download url invalid."')
		quit()

# Paths to relevant files or folders
goblint_path = '../../analyzer/goblint' # DEFAULT
testsupport_path = 'C/testcasesupport' # DEFAULT
testsupport_files = testsupport_path + '/*.c'
path = 'C/testcases/CWE366_Race_Condition_Within_Thread' # Can be changed by CL input

# Command line input
if len(sys.argv) == 2:
	path = sys.argv[1] # path + '/' + sys.argv[1]
	# Checking if the path is valid
	if not os.path.exists(juliet_path):
		os.system('echo "PATH NOT FOUND: "' + path)	
elif len(sys.argv) != 1:
	os.system('echo "FAILURE: Run script with no arguments to run on all testcases or add path to a specific testcases folder (that has individual cases or folders containing testcases)."')
	quit()


# # # FUNCTIONS # # #

	
# Goes through all the files in given path, returns all suitable testcase files and 
# all directories that might potentially contain testcases1
def check_path(filepath):
	files = os.listdir(filepath)
	v_files = [] # Valid files
	dirs = [] # Directories
	for f in files:
		if re.search('^CWE', f) != None and re.search('[0-9]{2}a?\.c$', f) != None and re.search('w32', f) == None: v_files.append(f)
		elif os.path.isdir(filepath + '/' + f): 
			dirs.append(f)
	return v_files, dirs
	
# Runs Goblint to process a testcase function, testcase function will be either
# '_good' or '_bad' determined by input parameter 'mode'
def run_function(filepath, filename, mode):
	func = re.sub('a?\.c$', mode, filename) # File ending is cut and replaced by mode
	cmd = goblint_path + ' ' + filepath + ' ' + testsupport_files + ' -I ' + testsupport_path + ' --sets "mainfun[+]" ' + func + ' --enable printstats'
	print(filename)
	process = subprocess.run(cmd, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)
	#title = '#####################\n' + mode.upper() + '\n#####################\n\n'
	return cmd + "\n\n" + process.stdout + process.stderr
	
# Takes a list of testcase files as input and iterates through them to analyze 
# outputs for both 'good' and 'bad' function. Generates a HTML table based on outputs.
def goblint_files(testcases, filepath, html_table):
	# Creating column headers for the table
	html_table += '\n<p id="' + filepath + '">Folder: ' + filepath + '&emsp;<a href="#top">Go to top</a></p>\n'
	html_table += "<table border=1>\n"
	header = ['Testcase', 'Good', 'Bad']
	html_table += "  <tr>\n"
	for column in header:
		html_table += "    <th>{0}</th>\n".format(column.strip())
	html_table += "  </tr>\n"
	# Going through valid testcase files
	testcases.sort()	
	for t in testcases:
		f_path = filepath + '/' + t
		v_good = '-' # Vulnerabilities in 'good', initial value: nothing found
		v_bad = '-' # Vulnerabilities in 'bad', initial value: nothing found
		output_good = 'Function missing / Error unrelated to Goblint\n' # initial value
		output_bad = 'Function missing / Error unrelated to Goblint\n' # initial value
		# The upcoming 'try' statements are used because at least one test case 
		#from Juliet suite does not contain both functions.
		try:
			output_good = run_function(f_path, t, '_good') # 'good' function
			if re.search('Summary for all memory locations:', output_good) != None:
				v_good = 'X'
		except: v_good = '?'
		try:
			output_bad = run_function(f_path, t, '_bad') # 'bad' function
			if re.search('Summary for all memory locations:', output_bad) != None:
				v_bad = 'X'
		except: v_bad = '?'
		
		# Generating .txt file for the output
		title = t + '\n\n'
		good_title = '#####################\n_GOOD\n#####################\n\n'
		bad_title = '#####################\n_BAD\n#####################\n\n'
		output_string = title + good_title + output_good + '\n' + bad_title + output_bad + '\n'
		output_file = outputs_path + '/' + t + '.txt'
		with open(output_file, "w", encoding="utf-8") as file:
			file.write(output_string)
		# HTML
		output_html = '<a href="' + output_file + '" target="_blank">' + t + '</a>'
		result = [output_html, v_good, v_bad]
		html_table += "  <tr>\n"
		for column in result:
			html_table += "    <td>{0}</td>\n".format(column.strip())
		html_table += "</tr>\n"
	html_table += "</table><br><hr><br>\n"
	return html_table


# # # MAIN PROCEDURES # # #

	
# Blanks for HTML content
table = ''
contents_href = []

# Generating directory for output text files
outputs_path = 'C/juliet_summary_fileoutputs' # Path to outputs directory
if not os.path.exists(outputs_path):
    os.makedirs(outputs_path)


# Starting with files in the running directory
current_dir = path
valid_files, directories = check_path(current_dir)
if len(valid_files) > 0:
	os.system('echo ' + current_dir) # For keeping track of the progress	
	table = goblint_files(valid_files, current_dir, table)
	contents_href.append(current_dir)
		
# Going through the main CWE directories if present
directories.sort()
for d in directories:
	current_dir = path + '/' + d
	valid_files, sub_directories = check_path(current_dir)
	if len(valid_files) > 0:
		os.system('echo ' + current_dir)
		table = goblint_files(valid_files, current_dir, table)
		contents_href.append(current_dir)
	# When the main CWE dir is split into sub-directories (s01, s02, ...)
	sub_directories.sort()
	for s in sub_directories:
		current_subdir = current_dir + '/' + s
		valid_files, nodir = check_path(current_subdir)
		if len(valid_files) > 0:
			os.system('echo ' + current_subdir)
			table = goblint_files(valid_files, current_subdir, table)
			contents_href.append(current_subdir)		

# Generating content for HTML
contents = '<p id="top" style="font-size:30px">RESULTS</p>\n'
contents += '<p><small><strong>X</strong>&emsp;Vulnerabilities detected</small></p>\n'
contents += '<p><small><strong>-</strong>&emsp;No vulnerabilities detected</small></p>\n'
contents += '<p><small><strong>?</strong>&emsp;Function not found, error</small></p><br>\n'
for ref in contents_href:
	contents += '<a href="#' + ref + '">' + ref + '</a>\n'
table = contents + '<br><hr><br>\n' + table + '<a href="#top">Go to top</a>'		
# Creating HTML file
with open('summary_table.html', 'w', encoding='utf-8') as file:
	file.write(table)	
