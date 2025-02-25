import random

def generate_random_numbers(filename, count, min_val=1, max_val=10000000):
    with open(filename, 'w') as f:
        for _ in range(count):
            f.write(f"{random.randint(min_val, max_val)}\n")

if __name__ == "__main__":
    generate_random_numbers("inputs_10M.txt", 10000000)
    print("Generated 100000 random numbers and saved them to inputs.txt")
