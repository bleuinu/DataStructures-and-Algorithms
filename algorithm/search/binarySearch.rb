def binary_search(arr, target)
  low = 0
  high = arr.size

  while low <= high 
    mid = low + (high - low) / 2
     
    return mid if arr[mid] == target 
    if target < arr[mid]
      high = mid - 1
    else 
      low = mid + 1
    end 

    nil
  end

  nil 
end

arr = [10, 20, 80, 30, 60, 50, 110, 100, 130, 170]
arr.sort!
p arr
puts
print("search for? ")
x = gets.to_i

index = binary_search(arr, x)
if index == nil 
  puts "element #{x} is not in the array"
else
  puts "element #{x} is at index #{index}"
end
