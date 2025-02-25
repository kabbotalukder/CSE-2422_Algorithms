import random

def generate_random_numbers(filename, count, min_val=1, max_val=100000):
    with open(filename, 'w') as f:
        for i in range(count):
            #f.write(f"{random.randint(min_val, max_val)}\n")
            f.write(f"{count - i}\n")


generate_random_numbers("inputs_100Kdes.txt", 100000)
print("Generated random numbers and saved them to inputs.txt")
