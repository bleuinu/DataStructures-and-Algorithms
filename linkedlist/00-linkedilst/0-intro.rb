# Node class
class Node 
  attr_accessor :next 

  def initialize(data) 
    @data = data
    @next = nil
  end

  def get_data 
    @data
  end
end 

# Linked List Class
class LinkedList 
  attr_accessor :head 

  def initialize 
    @head = nil
  end

  # traversal
  def print
    return if @head == nil

    temp = @head 
    while temp != nil do
      puts temp.get_data 
      temp = temp.next
    end
  end
end

llist = LinkedList.new 
llist.head = Node.new(1)
second = Node.new(2)
third = Node.new(3)

llist.head.next = second 
second.next = third 
third.next = Node.new(17)
third.next.next = Node.new(25)

llist.print
