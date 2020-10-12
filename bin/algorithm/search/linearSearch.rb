def linear_search(arr, target)
  arr.each_with_index do |x, i|
    return i if x == target
  end

  nil 
end

arr = [10, 20, 80, 30, 60, 50, 110, 100, 130, 170]
p arr
puts
print("search for? ")
x = gets.to_i

index = linear_search(arr, x)
if index == nil 
  puts "element #{x} is not in the array"
else
  puts "element #{x} is at index #{index}"
end
