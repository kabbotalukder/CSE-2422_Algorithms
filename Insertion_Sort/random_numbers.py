import random

def generate_random_numbers(filename, count, min_val=1, max_val=500000):
    with open(filename, 'w') as f:
        for _ in range(count):
            f.write(f"{random.randint(min_val, max_val)}\n")


generate_random_numbers("inputs_500K.txt", 500000)
print("Generated random numbers and saved them to inputs.txt")
