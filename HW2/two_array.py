l1 = [7,6,1,2,3,4,5] 
l2 = [10,9,8,5,6,7] 

# Step one Sort it 
# Step Two Merge Two lists 

count_of_shift = 0 

# O(n)
for i in range(1,len(l1)) : 
     if l1[i] < l1[i-1] : 
         count_of_shift += 1 

count_of_shift2 = 0 
# O(n)
for i in range(1,len(l2)) : 
    if l2[i] < l2[i-1] : 
        count_of_shift2 += 1 

# O(n)
for i in range(count_of_shift-1,-1,-1) : 
    # if it was linked list order is 1+1 = 2 (so thats a number = 0 :) )
    l1.append(l1.pop(i))

# O(n)
for i in range(count_of_shift2-1,-1,-1) : 
    l2.append(l2.pop(i))

# Now Merging lists 
for i in range(len(l2)) : 
    l1.append(l2[i])
sorted(l1+l2) 

print(l1)
if len(l1) % 2 == 0 : 
    print(l1[(len(l1)/2 -1 )])
else : 
    index = (l1[int(len(l1)/2 -1 )])
    print((l1[index+1] - l1[index+1]) / 2)

