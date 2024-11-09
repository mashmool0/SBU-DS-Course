lst = [
    [0,0,3,0,4],
    [0,0,5,7,0],
    [0,0,0,0,0],
    [0,2,6,0,0],
]
# lst = [
#     [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12],
#     [0, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23],
#     [0, 0, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33],
#     [0, 0, 0, 34, 35, 36, 37, 38, 39, 40, 41, 42],
#     [0, 0, 0, 0, 43, 44, 45, 46, 47, 48, 49, 50],
#     [0, 0, 0, 0, 0, 51, 52, 53, 54, 55, 56, 57],
#     [0, 0, 0, 0, 0, 0, 58, 59, 60, 61, 62, 63],
#     [0, 0, 0, 0, 0, 0, 0, 64, 65, 66, 67, 68],
#     [0, 0, 0, 0, 0, 0, 0, 0, 69, 70, 71, 72],
#     [0, 0, 0, 0, 0, 0, 0, 0, 0, 73, 74, 75],
#     [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 76, 77],
#     [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 78]
# ]

n = len(lst)
n2 = len(lst[0])

none_zero_list = [
    [], # For save Row of None zero 
    [], # col 
    [], # Val 
]

for i in range(len(lst)) : 

    for j in range(len(lst[0])) :  
        if lst[i][j] != 0  : 
            none_zero_list[2].append(lst[i][j]) 
            none_zero_list[1].append(j)
            none_zero_list[0].append(i)
        
    

for item,name in zip(none_zero_list,['Row','Col','Value']): 
    print(f'{name} = {item}')

# Is it good ?  Lets Check it 
main_list = n*n2 
second_list =  len(none_zero_list[0]) * 3 
print(main_list)
print(second_list)

print(f'{((main_list - second_list) / main_list) * 100}% is better than last')
