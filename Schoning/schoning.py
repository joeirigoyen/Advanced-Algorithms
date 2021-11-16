import os
import random
from reader import read_file, write_on_file, create_file

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
        variables[i + 1] = randbool


# Check whether a formula returns true or false
def check_cond(formula: list) -> bool:
    flag = False
    for c in formula:
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
def update_random(formula: list) -> None:
    for c in formula:
        key = abs(int(c))
        variables[key] = randbool()


# Show the results for every formula within a list
def show_result(n: int, forms: list) -> None:
    for i in range(n):
        print(check_cond(forms[i]))
    print()


# Main
if __name__ == '__main__':
    # Input source filename
    source_file_name = input("Source file directory: ")
    source_file_path = os.path.abspath(source_file_name)
    # Create result file
    result_file_name = f"result_{source_file_name}"
    create_file(result_file_name)
    # Write input file into result file
    source_file = open(source_file_path, "r")
    write_on_file(os.path.abspath(result_file_name), source_file.readlines)
    # Initialize dictionary
    n, forms = read_file(source_file_path)
    init_variables(n)
    # Show initial results
    show_result(n, forms)
    # Do Schoning algorithm
    for i in range(3):
        for j in range(n):
            if not (check_cond(forms[j])):
                update_random(forms[j])
    # Show final results
    show_result(n, forms)