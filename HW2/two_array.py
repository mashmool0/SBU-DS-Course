def check_rotate(l:list) : 
    rotate = 0 
    for i in range(1,len(l)) : 
        if l[i]  < l [i-1] : 
            rotate += 1 
    return rotate 

def shift_list(l:list,rotate:int) :
    for i in range(rotate-1,-1,-1) : 
        l.append(l.pop(i))
    

def merge_arrays(arr1, arr2):
    merged_array = []
    i, j = 0, 0

    while i < len(arr1) and j < len(arr2):
        if arr1[i] < arr2[j]:
            merged_array.append(arr1[i])
            i += 1
        else:
            merged_array.append(arr2[j])
            j += 1

    while i < len(arr1):
        merged_array.append(arr1[i])
        i += 1

    while j < len(arr2):
        merged_array.append(arr2[j])
        j += 1

    return merged_array

def find_median(merged_array):
    n = len(merged_array)
    if n % 2 == 1:
        return merged_array[n // 2]
    else:
        mid1, mid2 = merged_array[(n // 2) - 1], merged_array[n // 2]
        return (mid1 + mid2) / 2

l1 = [7,6,1,2,3,4,5] 
l2 = [10,9,8,5,6,7] 

rotate = check_rotate(l1)
rotate2 = check_rotate(l2)
shift_list(l1,rotate)
shift_list(l2,rotate2)
merged_list = merge_arrays(l1,l2)
print(l1)
print(l2)
print(merged_list)

print(find_median(merged_list))
