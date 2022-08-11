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
path = 'C/testcases' # Can be changed by CL input

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


# The definitive function that performs all the main operations:
#	- Takes current working directory and HTML contents as input
#	- Finds valid C files for Goblint in that dir and establishes
#	other potential sub-directories for the future
#	- Runs Goblint on valid test cases if they exist
#	- Generates HTML table with new results from those cases
#	- Returns potential directories and new HTML contents
def goblint_analyse(current_directory, HTML_info):
	# Getting valid C files and potential directories for further work
	valid_files, pot_directories = check_path(current_directory)
	# In case there are valid C files to analyse with Goblint
	if len(valid_files) > 0:
		os.system('echo ' + current_directory) # Feedback to the user
		# Generating HTML table with new results from Goblint
		HTML_info[0] = files_output_to_HTML(valid_files, current_directory, HTML_info[0])
		HTML_info[1].append(current_directory)
	return pot_directories, HTML_info

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
def goblint_cmd(filepath, filename, mode):
	func = re.sub('a?\.c$', mode, filename) # File ending is cut and replaced by mode
	cmd = goblint_path + ' ' + filepath + ' ' + testsupport_files + ' -I ' + testsupport_path + ' --sets "mainfun[+]" ' + func + ' --enable dbg.debug --enable printstats'
	print(filename + ' -- ' + mode[1:] + '     ', end='\r')
	process = subprocess.run(cmd, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)
	#title = '#####################\n' + mode.upper() + '\n#####################\n\n'
	return cmd + "\n\n" + process.stdout + process.stderr

# Takes a list of testcase files as input and iterates through them to analyze
# outputs for both 'good' and 'bad' function. Generates an HTML table based on outputs.
def files_output_to_HTML(testcases, filepath, html_table):
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
			output_good = goblint_cmd(f_path, t, '_good') # 'good' function
			if re.search(v_detection, output_good) != None:
				v_good = 'X'
		except: v_good = '?'
		try:
			output_bad = goblint_cmd(f_path, t, '_bad') # 'bad' function
			if re.search(v_detection, output_bad) != None:
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
	print('')
	return html_table


# # # MAIN PROCEDURES # # #

# Regex string that is used to confirm that vulnerabilities were detected
v_detection = 'is dead!|Summary for all memory locations:'

# Blanks for HTML content
# '' - empty string for HTML table that will contain results from Goblint
# [] - empty array for href values that will be used for table of contents
HTML = ['', []]

# Generating directory for output text files
outputs_path = 'C/juliet_summary_fileoutputs' # Path to outputs directory
if not os.path.exists(outputs_path):
    os.makedirs(outputs_path)

# Running Goblint and generating content for HTML

# Starting with files in the running directory
current_dir = path
# Running Goblint on current directory and getting new potential sub-directories
directories, HTML = goblint_analyse(current_dir, HTML)

# Going through the main CWE directories if present
directories.sort()
for d in directories:
	current_dir = path + '/' + d
	# Running Goblint, getting new sub-directories
	sub_directories, HTML = goblint_analyse(current_dir, HTML)
	# When the main CWE dir is split into sub-directories (s01, s02, ...)
	sub_directories.sort()
	for s in sub_directories:
		current_subdir = current_dir + '/' + s
		# Running Goblint, max depth achieved so no sub-directories
		goblint_analyse(current_subdir, HTML)


# Generating content for HTML
HTML_content = '<p id="top" style="font-size:30px">RESULTS</p>\n'
HTML_content += '<p><small><strong>X</strong>&emsp;Vulnerabilities detected</small></p>\n'
HTML_content += '<p><small><strong>-</strong>&emsp;No vulnerabilities detected</small></p>\n'
HTML_content += '<p><small><strong>?</strong>&emsp;Function not found, error</small></p><br>\n'
# Creating table of contents using href linking
for href in HTML[1]:
	HTML_content += '<a href="#' + href + '">' + href + '</a><br>\n'
# Adding table of contents and results table together
HTML_content = HTML_content + '<br><hr><br>\n' + HTML[0] + '<a href="#top">Go to top</a>'
# Creating HTML file
with open('summary_table.html', 'w', encoding='utf-8') as file:
	file.write(HTML_content)
