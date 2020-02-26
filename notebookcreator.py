import os
import subprocess


def cpy_template():
    os.system('cp template.tex notebook.tex')


def get_dir():
    path = 'C++'
    items = os.listdir(path)
    section = []
    for itemname in items:
        subsection = []
        files = os.listdir(os.path.join(path, itemname))
        for filename in files:
            if filename.endswith('.cpp') or filename.endswith('.tex'):
                subsection.append(filename)
        section.append((itemname, subsection))
    return section


def create_notebook(section):
    path = 'C++'
    aux = ''
    with open('notebook.tex', 'a') as texfile:

        for (item, subsection) in section:
            aux += '\\section{%s}\n' % item
            for file in subsection:
                name, ext = os.path.splitext(file)
                if ext == '.cpp':
                    aux += '\\includes{%s}{%s}\n' % \
                        (name, os.path.join(path, item, file))
                elif ext == '.tex':
                    aux += '\\subsection{%s}' % name
                    aux += '\\input{%s}\n' % \
                        (os.path.join(path, item, file))

        aux += '\n\\end{multicols}\n\\end{document}\n'
        texfile.write(aux)


cpy_template()
section = get_dir()
create_notebook(section)
subprocess.call(['latexmk', '-pdf', 'notebook.tex'])

subprocess.call(['rm', 'notebook.aux', 'notebook.fdb_latexmk',
                 'notebook.fls', 'notebook.log'])
