twoD_list = [
    # Sample Data 
    [1,0,1,1,0,1,0,1],
    [0,0,1,0,1,1,1,0],
    [0,0,1,1,1,0,0,0]
]

# Algorithm for Checking movies user  Watch


# print(f'choose your user for count of movies usres list -> (0,{len(twoD_list) -1 })')
# which_user = int(input("Etner your user id : ")) 
# count  = 0 
# for movie in twoD_list[which_user] : 
#     if movie : 
#         count += 1 

# print("print count of movie user see : " , count)

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



