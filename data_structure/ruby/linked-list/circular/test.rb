require './cll.rb'

list = nil

case ARGV[0]
when 'singly' then
  list = CircularLinkedList::Singly.new
  puts "Testing Circular Singly Linked List.... press enter"
when 'doubly' then
  list = CircularLinkedList::Doubly.new
  puts "Testing Circular Doubly Linked List.... press enter"
else
  puts "$ ruby test.rb [singly | doubly]"
  return
end

puts "Insert at the back [1, 2, 3]"
list.insert(1)
list.print_list
list.insert(2)
list.print_list
list.insert(3)
list.print_list

puts "================================"

puts "Insert at the front [4, 5, 6]"
list.insert_at(0, 4)
list.print_list
list.insert_at(0, 5)
list.print_list
list.insert_at(0, 6)
list.print_list

puts "================================"

puts "Insert 10 at index 3"
list.insert_at(3, 10)
list.print_list
puts "Insert 20 at index 6"
list.insert_at(6, 20)
list.print_list
puts "Insert 30 at index 8"
list.insert_at(8, 30)
list.print_list

puts "================================"

puts "remove front"
puts "removed #{list.remove_at(0)}"
list.print_list

puts "removed #{list.remove_at(0)}"
list.print_list

puts "removed #{list.remove_at(0)}"
list.print_list

puts "================================"

puts "remove last"
puts "removed #{list.remove_last}"
list.print_list
puts "removed #{list.remove_last}"
list.print_list
puts "removed #{list.remove_last}"
list.print_list
puts "removed #{list.remove_last}"
list.print_list
puts "removed #{list.remove_last}"
list.print_list

puts "================================"

puts "insert 9 at the back"
list.insert(9)
list.print_list

puts "================================"

puts "insert 99 at the front"
list.insert_at(0, 99)
list.print_list

puts "================================"

puts "insert 999 at index 1"
list.insert_at(1, 999)
list.print_list

puts "================================"

puts "remove at index 2"
list.remove_at(2)
list.print_list

puts "================================"

while !list.empty? do
  puts "removed #{list.remove_at(0)}"
  list.print_list
end

puts "================================"

puts "insert 7 at index 1"
list.insert_at(1, 7)
list.print_list
puts "insert 7 at index 0"
list.insert_at(0, 7)
list.print_list

puts "insert 77 at index 1"
list.insert_at(1, 77)
list.print_list

puts "insert 5 at the back"
list.insert(5)
list.print_list

puts "================================"

while !list.empty? do
  puts "removed #{list.remove_at(0)}"
  list.print_list
end
