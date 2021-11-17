import os


def read_file(filename: str) -> tuple:
    variables = 0
    conditions = []
    KSAT_TYPE = 3
    f = open(filename, "r")
    for line in f:
        if line[0] != 'c':
            words = line.split()
            if words[0] == 'p':
                variables = int(words[-2])
            else:
                words = words[:KSAT_TYPE]
                conditions.append(words)
    f.close()
    return (variables, conditions)
        
        
def write_on_file(filename: str, content: str) -> None:
    file_path = os.path.abspath(filename)
    f = open(file_path, "a+")
    f.write(content)
    f.close()
    

def write_on_file(filename: str, contents: list) -> None:
    file_path = os.path.abspath(filename)
    f = open(file_path, "a+")
    for i in contents:
        f.write(i)
