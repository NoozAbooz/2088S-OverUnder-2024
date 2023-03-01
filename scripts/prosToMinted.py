from pathlib import Path
import zipfile
from shutil import copy, rmtree
import os

# Function which zips the given 'path' to the 'ziph'
def zipdir(path, ziph):
    for root, dirs, files in os.walk(path):
        for file in files:
            ziph.write(os.path.join(root, file))

# main function
def main():
    if Path('project.pros').exists():
        print("\033[92m" + "FOUND PROJECT FILE " + u"\u2193" + "\033[0m")
        root = Path('project.pros')
        root_array = root.cwd().parts
        PROJECT_NAME = root_array[-1]
        ROOT_START = len(root_array)

    try:
        print(("\033[95m" + str(root) + " | " + str(type(root)) + "\033[0m"))
    except:
        print("\033[91m" + "Please navigate to the root directory of the PROS project" + "\033[0m")
        print("\033[93m" + "Need help setting up? See: https://github.com/Udit8348/Hard-Copy#setup" + "\033[0m")
        return -1

    try:
        # create a temp directory to store all the tex files we want to print
        zip_source = root.cwd()  / "output"
        zip_source.mkdir(parents=True, exist_ok=True)
    except FileExistsError as e:
        print(e)

    try:
        # create a permanent directory to store all the files we want to print
        docs_dest = root.cwd()  / "docs"
        docs_dest.mkdir(parents=True, exist_ok=True)
    except FileExistsError as e:
        # If the directory already exists, skip creating a new one
        print("Docs directory already exists at: " + e)

    # Create the path to a wrapper.tex file
    wrapper_dest = zip_source / "wrapper.tex"
    wrapper_dest.touch(exist_ok=True)
    with wrapper_dest.open(mode='w') as f:
        # Recursively search the entire project for any header files
        f.write("%%---------------------\n")
        f.write("\\section{Header Files}\n\n")
        for header in root.cwd().glob('**/*.h*'):
            # break header into components starting from the root
            components = header.parts[ROOT_START:]

            # Exclude default PROS headers and restrict search to sub-directories of include/
            # It is good convention to keep all your header files in include/
            # Sub directories within include/ will still be found
            if('api.h' in components
            or ('include' and 'pros') in components
            or ('include' and 'okapi') in components
            or ('include' and 'display') in components
            or ('include' and 'output') in components
            or 'cquery_cached_index' in components
            or (not 'include') in components
            or '.vscode' in components):
                continue

            # Build a relative unix path for Overleaf to find the includes
            rel_header_path = ""
            for i in range(0, len(components)-1):
                rel_header_path += components[i] + "/"
            name = components[-1]
            rel_header_path += name
            copy(header, zip_source)


            # Generate LaTeX code for any valid header
            # Write it to the 'Code' LaTeX file
            f.write("\\subsection{" + rel_header_path + "}\n")
            f.write("\\inputminted[linenos,tabsize=2,breaklines, breakanywhere]{c}{" + name + "}\n")
            f.write("\\pagebreak\n\n")

        # Recursively search the entire project for any relevant source files
        f.write("%%---------------------\n")
        f.write("\\section{Source Files}\n\n")
        for source in root.cwd().glob('**/*.c*'):
            # break source into components starting from the root
            components = source.parts[ROOT_START:]

            '''
                It is good practice to only have .c and .cpp files in src
                PROS projects may contain .c image arrays or .csv files but
                those should be organized outside of src directory
            '''
            if(not 'src' in components):
                continue

            # Build a relative unix path for Overleaf to find the source files
            rel_src_path = ""
            for i in range(0, len(components)-1):
                rel_src_path += components[i] + "/"
            name = components[-1]
            rel_src_path += name
            copy(source, zip_source)

            # Generate LaTeX code for any valid source file
            f.write("\\subsection{" + rel_src_path + "}\n")
            f.write("\\inputminted[linenos,tabsize=2,breaklines, breakanywhere]{c}{" + name + "}\n")
            f.write("\\pagebreak\n\n")

    # Create the path to a main.tex file and insert boilerplate tex code
    main_dest = zip_source / "main.tex"
    main_dest.touch(exist_ok=True)
    with main_dest.open("w") as f:
        f.write("\\documentclass{article}\n"
                 + "\\usepackage[utf8]{inputenc}\n"
                 + "\\usepackage[margin=1in]{geometry}\n"
                 + "\\title{" + PROJECT_NAME + "}\n"
                 + "\\author{LAST_FIRST}\n"
                 + "\\date{MONTH_YEAR}\n"
                 + "\\usepackage{minted}\n"
                 + "\\begin{document}\n\n"
                 + "\\input{wrapper.tex}\n\n"
                 + "\\end{document}")

    '''
    Ultimately, create a zipfile which can be automatically read by Overleaf
    '''
    # Create Path objects to the output zip and the temp folder containing all the assets
    zip_dest = docs_dest / "output.zip"


    # create a ZipFile object with the provided parameters
    zipf = zipfile.ZipFile(str(zip_dest), mode='w', compression=zipfile.ZIP_DEFLATED)

    # Function (defined above) recursively writes each file to the zip
    zip_source_truncated = Path('.') / 'output'
    zipdir(str(zip_source_truncated), zipf)
    zipf.close()

    # Recursively delete output folder once we have zipped it
    try:
        rmtree(str(zip_source_truncated))
    except OSError as e:
        print(e)

    print("\033[92m" + "Success! Find your zip at: docs/output.zip" + "\033[0m")
    print("Upload the zip directly to overleaf and let it compile into a PDF!")
    print("Need help troubleshooting? See: https://github.com/Udit8348/Hard-Copy#troubleshooting")


if __name__ == "__main__":
    # v 1.0
    main()
