import random

def generate_random_numbers(filename, count, min_val=1, max_val=5000000):
    with open(filename, 'w') as f:
        for i in range(count):
            #f.write(f"{random.randint(min_val, max_val)}\n")
            f.write(f"{random.randint(min_val, max_val)}\n")


generate_random_numbers("inputs_5M.txt", 5000000)
print("Generated random numbers and saved them to inputs.txt")
