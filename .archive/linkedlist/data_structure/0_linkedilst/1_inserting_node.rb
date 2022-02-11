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
    puts "[initialize LinkedList]"
    @node_count = 0
    @head = nil
  end

  # traversal
  def print_list
    puts "[print_list]"
    return if @head == nil

    temp = @head 
    $stdout.sync = true
    while temp != nil do
      print "#{temp.get_data} " 
      temp = temp.next
    end
    puts
  end

  # Insert at front 
  def push_front(data) 
    puts "[push_front] inserting #{data} at the front"
    new_head = Node.new(data)
    new_head.next = @head 
    @head = new_head
    @node_count += 1
    nil
  end 

  # Insert  at last 
  def push_back(data) 
    puts "[push_back] inserting #{data} at the end"
    tail = Node.new(data)
    temp = @head
    while temp.next != nil
      temp = temp.next 
    end 

    temp.next = tail
    @node_count += 1
    nil
  end 

  # Insert in between (index = zero-based)
  def insert_at(data, idx)
    puts "[insert_at] inserting #{data} at index #{idx}"
    if idx <= 0 
      push_front(data)
    elsif idx >= @node_count 
      push_back(data)
    else 
      temp = @head 
      (idx-1).times { temp = temp.next }
      
      new_node = Node.new(data)
      new_node.next = temp.next 
      temp.next = new_node

      @node_count += 1
    end 

    nil
  end
end

llist = LinkedList.new 
llist.head = Node.new(1)
second = Node.new(2)
third = Node.new(3)

llist.head.next = second
second.next = third 

llist.print_list

llist.push_front(0)
llist.push_front(-1)
llist.push_front(-2)

llist.print_list

llist.push_back(4)
llist.push_back(5)
llist.push_back(6)

llist.print_list

llist.insert_at(77, 0)
llist.insert_at(77, 5)
llist.insert_at(77, 10)

llist.print_list
