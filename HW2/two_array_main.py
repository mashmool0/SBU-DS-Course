def find_rotation_count(arr):
    for i in range(1, len(arr)):
        if arr[i] < arr[i - 1]:
            return i
    return 0  # No rotation if already sorted

def rotate_array(arr, rotate_count):
    return arr[rotate_count:] + arr[:rotate_count]

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

    # Append remaining elements from arr1
    while i < len(arr1):
        merged_array.append(arr1[i])
        i += 1

    # Append remaining elements from arr2
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

# Main function
def main():
    l1 = [7, 6, 1, 2, 3, 4, 5]
    l2 = [10, 9, 8, 5, 6, 7]

    # Find rotation counts
    rotate_count1 = find_rotation_count(l1)
    rotate_count2 = find_rotation_count(l2)
    

    # Rotate arrays back to sorted form
    sorted_l1 = rotate_array(l1, rotate_count1)
    sorted_l2 = rotate_array(l2, rotate_count2)
    print(sorted_l1)
    print(sorted_l2)
    # Merge arrays
    merged_array = merge_arrays(sorted_l1, sorted_l2)

    # Find median
    median = find_median(merged_array)
    print("Median:", median)

main()
