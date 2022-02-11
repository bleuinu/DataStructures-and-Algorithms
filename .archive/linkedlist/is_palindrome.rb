=begin 
Function to check if a singly linked list is palindrome
=end 

require '../01-singly-linkedlist/0-slist.rb'

class SinglyLinkedList 
  def is_palindrome?
    mid = midnode 
    curr = @head 

    first_half = []
    second_half = []

    while curr != mid do 
      first_half << curr.data 
      curr = curr.next 
    end 

    while mid != nil do 
      second_half << mid.data 
      mid = mid.next 
    end 

    second_half.shift if second_half.size > first_half.size 
  
    first_half.size.times do |idx|
      return false if first_half[idx] != second_half[second_half.size-1-idx]
    end 

    return true
  end

  def midnode
    mid = @head 
    curr = @head 
    idx = 0
    while curr.next != nil 
      curr = curr.next 
      if ((idx+1)&1) == 1 
        mid = mid.next
      end 
      idx += 1
    end 

    return mid
  end
end 

slist = SinglyLinkedList.new('R')
slist.push_back('A')
slist.push_back('C')
slist.push_back('E')
slist.push_back('C')
slist.push_back('A')
slist.push_back('R')
slist.print_list

if slist.is_palindrome?
  puts "It's a palindrome"
else 
  puts "It's NOT a palindrome"
end
