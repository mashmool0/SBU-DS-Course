twoD_list = [
    # Sample Data 
    [1,0,1,1,0,1,0,1],
    [0,0,1,0,1,1,1,0],
    [0,0,1,1,1,0,0,0]
]

biggest = 0 
column = -1 
# Algorithm for Best Movie 
for i in range(len(twoD_list[0])) : 
    count = 0 
    for j in range(len(twoD_list)) : 
        count += twoD_list[j][i] 
    
    if count > biggest : 
        biggest = count 
        column = i  
        

print(column,biggest)



