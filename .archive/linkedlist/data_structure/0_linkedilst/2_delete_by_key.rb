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

  # Delete a node
  def delete(data)
    puts "[delete] trying to delete #{data}"
    if @head.get_data == data
      @head = @head.next 
      @node_count -= 1
      return true
    end 

    node_previous = lookup(data)

    if node_previous == nil 
      puts "There is no node with #{data}"
      return false
    else
      node_previous.next = node_previous.next.next
      @node_count -= 1
    end

    return true
  end 

  # delete all node with a value == data 
  def delete_all(data)
    puts "[delete_all] delete all nodes with #{data}"
    while true 
      break if !delete(data)
    end
  end 

  # looks for a node with a value == data,
  # returns the node previous to that
  def lookup(data)
    puts "[lookup] trying to find a node with #{data}"
    return @head if @head.get_data == data

    temp = @head
    while temp.next != nil 
      return temp if temp.next.get_data == data
      temp = temp.next 
    end 

    nil 
  end 
end

llist = LinkedList.new 
llist.head = Node.new(1)

# randomly populate 10 nodes
10.times { llist.push_back(rand(17)+1) }
llist.print_list

llist.delete(1)
llist.print_list

llist.delete(5)
llist.print_list

llist.delete(8)
llist.print_list

llist.delete(10)
llist.print_list

llist.delete_all(12)
llist.print_list
