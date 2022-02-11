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

  # Delete a node at a given position
  # idx = zero-based
  def delete_at(idx)
    puts "[delete_at] trying to delete a node at index #{idx}"

    if idx == 0 
      @head = @head.next 
      @node_count -= 1
      return
    end

    if idx >= @node_count
      puts "[idx >= @node_count] deleting the last node"
      idx = @node_count-1
    end 

    temp = @head 
    (idx-1).times { temp = temp.next }

    temp.next = temp.next.next
    @node_count -= 1
  end 
end

llist = LinkedList.new 
llist.head = Node.new(1)

# randomly populate 10 nodes
10.times { llist.push_back(rand(17)+1) }
llist.print_list

5.times do 
  llist.delete_at(rand(10))
  llist.print_list
end
