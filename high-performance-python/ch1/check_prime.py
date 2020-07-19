import math

def check_prime(number):
  sqrt_number = math.sqrt(number)
  number_float = float(number)
  for i in range(2, int(sqrt_number)+1):
    print(number_float/i)
    if (number_float / i).is_integer():
      return False
  return True

print(check_prime(181))
