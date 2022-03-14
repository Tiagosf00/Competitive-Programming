#! /usr/bin/python3

import os

def files(root):
    for entry in os.scandir(root):
        path = os.path.join(root, entry.name)
        if entry.is_file():
            yield path
        else:
            for x in files(path):
                yield x

for file in files("C++"):
    # if not file[-5:] == ".what":
    #     continue
    after = file.replace("-", "_")
    s = after.split('/')
    if s[-1][:9] != "README.md":
        s[-1] = s[-1].lower()
    after = os.path.join(*s)
    after += ".what"
    # after = after[:-5]
    if file != after:
        print(f"{file} -> {after}")
        os.replace(file, after)

