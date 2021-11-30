=begin 
Return the middle node of a given singly linked list
=end 

require '../01-singly-linkedlist/0-slist.rb'

class SinglyLinkedList 
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

slist = SinglyLinkedList.new
5.times { slist.push_back(rand(100)) }
slist.print_list

puts "Middle node: #{slist.midnode.data}"
