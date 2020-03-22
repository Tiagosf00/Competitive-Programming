import os
import subprocess
import shutil


def cpy_template():
    shutil.copyfile('template.tex', 'notebook.tex')


def remove_aux():
    if os.path.exists('notebook.aux'):
        os.remove('notebook.aux')
    if os.path.exists('notebook.log'):
        os.remove('notebook.log')
    # if os.path.exists('notebook.toc'):
    #     os.remove('notebook.toc')
    if os.path.exists('texput.log'):
        os.remove('texput.log')


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
# cmd = ['latexmk', '-pdf', '-silent', 'notebook.tex']
cmd = ['pdflatex', '-interaction=nonstopmode', '-halt-on-error',
       'notebook.tex']
with open(os.devnull, 'w') as DEVNULL:
    try:
        subprocess.check_call(cmd, stdout=DEVNULL)
    except Exception:
        print("Erro na transformação de LaTex para pdf.")
        exit(1)

remove_aux()

print("O PDF foi gerado com sucesso!")
