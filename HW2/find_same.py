lst1 = [
    [1,2,3,4],
    [2,4,7,8],
    [4,7,9,12],
    [3,3,5,3] ,
]

def Swap(i,j) : 
    help_num = lst1[j-1][i] 
    lst1[j-1][i] = lst1[j][i]
    lst1[j][i] = help_num
    

# Step One Sort it 
for i in range(len(lst1[0])) : 
    count = 0 
    while count != len(lst1[0]) : 
        for j in range(1,len(lst1)) : 
            if lst1[j][i]  < lst1[j-1][i] : 
                Swap(i,j)

        count += 1 

print("Sorted list :") 
for item in lst1 : 
    print(item)
    
print("--------------")

dict_numbers = {} 

for i in range(len(lst1)) : 
    dict_numbers[lst1[i][0]] = 1 


for i in range(1,len(lst1[0])) : 
    column = []
    for j in range(0,len(lst1)) : 
        if lst1[j][i] not in column : 
            column.append(lst1[j][i]) 
            if lst1[j][i] in list(dict_numbers.keys())  : 
                dict_numbers[lst1[j][i]] += 1 

print(dict_numbers)
max_num = 0 
key_val = 0 
for item in dict_numbers : 
    if dict_numbers[item] > max_num : 
        max_num = dict_numbers[item] 
        key_val = item 
    
print("-------")
print("Answer is : ")
print(key_val)