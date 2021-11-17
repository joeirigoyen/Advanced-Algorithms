import os
import random
from reader import read_file, write_on_file

# Dictionary
variables = {}


# Return a random boolean value
def randbool() -> bool:
    r = random.randint(0, 1)
    if r == 0:
        return False
    else:
        return True


# Initialize dictionary values
def init_variables(n: int) -> None:
    for i in range(n):
        variables[i + 1] = randbool()


# Check whether a formula returns true or false
def check_cond(clause: list) -> bool:
    flag = False
    for c in clause:
        key = int(c) 
        if key < 0:
            key *= -1
            flag = not variables[key]
        else:
            flag = variables[key]
        if flag:
            return True
    return False


# Randomly update the variables within the dictionary
def update_random(clause: list) -> int:
    rand_index = random.randint(0, len(clause) - 1)
    randkey = abs(int(clause[abs(rand_index)]))
    variables[randkey] = not variables[randkey]
    return rand_index, int(variables[randkey])


# Count satisifed and unsatisfied clauses
def count_clauses(clauses: list) -> None:
    sat, unsat = 0, 0
    for clause in clauses:
        if check_cond(clause):
            sat += 1
        else:
            unsat += 1
    return sat, unsat


# Show the results for every formula within a list
def show_dict(dictionary: dict) -> str:
    temp = ""
    for val in dictionary.values():
        if val:
            temp += '1'
        else:
            temp += '0'
    return temp


def show_clause(clause: list) -> str:
    temp = ""
    for i in range(len(clause)):
        x = int(clause[i])
        if x < 0:
            temp += "not "
        if i < len(clause) - 1:
            temp += f"x{abs(x)} or "
        else:
            temp += f"x{abs(x)}"
    return temp
            

# Main
if __name__ == '__main__':
    # Input source filename
    source_file_path_input = input("Source file directory: ")
    source_file_abs_path = os.path.abspath(source_file_path_input)
    # Create result file
    source_file_name = os.path.basename(source_file_abs_path)
    result_file_name = f"result_{source_file_name}"
    # Initialize dictionary
    n, clauses = read_file(source_file_abs_path)
    init_variables(n)
    sat, unsat = count_clauses(clauses)
    # Write initial string into result file
    f = open(result_file_name, "w")
    f.write(f"Initial string: {show_dict(variables)}\n")
    f.write(f"Satisfied: {sat} | Unsatisfied: {unsat}\n\n")
    # Do Schoning algorithm
    flag = True
    for i in range(3):
        flag = True
        f.write(f"Testing string: {show_dict(variables)}\n")
        for j in range(n):
            if not (check_cond(clauses[j])):
                flag = False
                f.write(f"Changed clause: {show_clause(clauses[j])}. ")
                index, new_val = update_random(clauses[j])
                f.write(" Flipped x" + str(abs(int(clauses[j][index]))) + f"\'s value to {new_val}" + "\n")
        # Show final results:
        if not flag:
            f.write(f"New string: {show_dict(variables)}\n\n")
        else:
            f.write("String satisfies formula\n")
            break
    if not flag:
        sat, unsat = count_clauses(clauses)
        f.write(f"Stats after 3 runs:\nSatisfied: {sat} | Unsatisfied: {unsat}\n\n")