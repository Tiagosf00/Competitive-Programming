import os


def cpy_template():
    os.system('cp template.tex notebook.tex')


def get_dir():
    items = os.listdir('C++/')
    section = []
    for itemname in items:
        subsection = []
        files = os.listdir('C++/'+itemname+'/')
        for filename in files:
            if filename.endswith('.cpp'):
                subsection.append(filename)
        section.append((itemname, subsection))
    return section


def create_notebook(section):
    aux = ''
    with open('notebook.tex', 'a') as texfile:

        for (item, subsection) in section:
            aux += '\\section{%s}\n' % item
            for file in subsection:
                aux += '\\includes{%s}{C++/%s/%s}\n' % (file, item, file)

        aux += '\n\\end{multicols}\n\\end{document}\n'
        texfile.write(aux)


cpy_template()
section = get_dir()
create_notebook(section)
