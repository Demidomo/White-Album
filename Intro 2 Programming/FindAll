import re

def is_prime(num):
    if num <= 1:
        return False
    if num <= 3:
        return True
    if num % 2 == 0 or num % 3 == 0:
        return False
    i = 5
    while i * i <= num:
        if num % i == 0 or num % (i + 2) == 0:
            return False
        i += 6
    return True

def display_prime_numbers(start):
    primes = [str(num) for num in range(start, start + 1000) if is_prime(num)]
    primes_str = " ".join(primes)
    return primes_str

if __name__ == "__main__":
    try:
        n = int(input("Enter an integer greater than 1: "))
        if n <= 1:
            print("Please enter an integer greater than 1.")
        else:
            prime_numbers = display_prime_numbers(n)
            print(f"Prime numbers greater than or equal to {n}:\n{prime_numbers}")
    except ValueError:
        print("Invalid input. Please enter a valid integer.")
