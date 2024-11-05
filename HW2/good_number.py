x, y, z = 3, 7, 17

n = int(input('n=')) - 1
m = int(input("m=")) - 1 

lst = []
lst_khoob = []
lst_kamel_khoob = []

num = 3 

def is_good(num, x, y, z):
    return num % x == 0 or num % y == 0 or num % z == 0

def is_perfect_good(num, x, y, z):
    # check how many numbers are divisible  (2 or more meand its perfect god )
    count_divisible = sum([num % x == 0, num % y == 0, num % z == 0])
    return count_divisible >= 2

while n >= len(lst_khoob) or m >= len(lst_kamel_khoob):
    if is_good(num, x, y, z):
        lst.append(num)
        lst_khoob.append(num)
        
    if is_perfect_good(num, x, y, z):
        lst.append(num)
        lst_kamel_khoob.append(num)
        
    num += 1

print("list of numbers ", lst)
print("list of good numbers ", lst_khoob)
print("list of perfect good number", lst_kamel_khoob)
print(f"n={lst_khoob[n]} , m={lst_kamel_khoob[m]}")
