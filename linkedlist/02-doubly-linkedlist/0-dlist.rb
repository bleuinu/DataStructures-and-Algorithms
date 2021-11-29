class Node 
  attr_accessor :next, :prev 
  attr_reader :data

  def initialize(data) 
    @data = data 
    @next = nil
    @prev = nil
  end 
end 

class DoublyLinkedList
  attr_accessor :head 
  attr_reader :node_count

  def initialize(data = nil)
    if data != nil 
    puts "[initialize] data = #{data}"
      @head = Node.new(data)
      @node_count = 1
    else 
      puts "[initialize] data = nil"
      @head = nil 
      @node_count = 0
    end 
  end 

  def push_front(data)
    puts "[push_front] inserting #{data} "
    new_node = Node.new(data)
    new_node.next = @head 
    @head.prev = new_node if @head
    @head = new_node

    @node_count += 1
  end 

  def push_back(data)
    puts "[push_back] inserting #{data}"
    if @head == nil 
      @head = Node.new(data) 
    else 
      curr = @head 
      while curr.next != nil 
        curr = curr.next 
      end 
      
      curr.next = Node.new(data)
      curr.next.prev = curr
    end 

    @node_count += 1
  end 

  # index = zero-based
  def insert_at(data, idx) 
    puts "[insert_at] insert #{data} at #{idx}"
    if idx <= 0
      puts "  index is <= 0"
      push_front(data)
    elsif idx >= @node_count 
      puts "  index is >= node_count(#{@node_count})"
      push_back(data)
    else 
      curr = @head
      idx.times { curr = curr.next }
      new_node = Node.new(data)
      curr.prev.next = new_node 
      new_node.prev = curr.prev
      curr.prev = new_node
      new_node.next = curr 

      @node_count += 1
    end 
  end 

  def pop_front
    if @node_count == 0 
      puts "[pop_front] no more nodes to pop"
    else 
      data = @head.data 
      @head = @head.next
      @head.prev = nil if @head != nil
      @node_count -= 1 

      puts "[pop_front] pop #{data}"
      return data 
    end
  end 

  def pop_back 
    if @node_count == 0 
      puts "[pop_back] no more nodes to pop"
    elsif @node_count == 1 
      data = @head.data 
      @head = nil 
      @node_count = 0 
      puts "[pop_back] pop #{data}"
      return data 
    else 
      curr = @head 
      (@node_count-1).times { curr = curr.next }
      data = curr.data
      curr.prev.next = nil 
      curr = nil
      @node_count -= 1 

      puts "[pop_back] pop #{data}"
      return data 
    end
  end 

  def delete_at(idx)
    puts "[delete_at] delete a node at index #{idx}"

    if @node_count == 0 
      puts "  [delete_at] no more nodes to delete"
    else 
      if idx <= 0
        puts "  [delete_at] idx <= 0... call pop_front"
        pop_front
      elsif idx >= (@node_count-1)
        puts "  [delete_at] idx >= node_count(#{@node_count})... call pop_back"
        pop_back 
      else 
        curr = @head 
        idx.times { curr = curr.next }
        curr.prev.next = curr.next 
        curr.next.prev = curr.prev
        data = curr.data
        curr = nil
        @node_count -= 1
        puts "[delete_at] deleted #{data}"
        return data
      end 
    end 
  end 

  def delete_node(data)
    puts "[delete_node] deleting a node with #{data}"
    index = find_node(data)
    if index == nil 
      puts "  couldn't find a node with #{data}"
    else 
      delete_at(index)
    end 
  end 

  def find_node(data) 
    puts "[find_node] looking for a node with #{data}"
    curr = @head 
    index = 0
    while curr != nil 
      return index if curr.data == data
      curr = curr.next 
      index += 1
    end 
    return nil 
  end 

  def print_list
    curr = @head 
    while curr && curr.next do 
      print "#{curr.data} <-> "
      curr = curr.next
    end 
    puts "#{curr.data}" if curr
  end 

  def reverse_print_list 
    puts "[Reverse Print List]"
    curr = @head 
    while curr && curr.next do 
      curr = curr.next 
    end 

    while curr != @head do
      print "#{curr.data} <-> "
      curr = curr.prev
    end
    puts "#{curr.data}" if curr
  end 
end 

dlist = DoublyLinkedList.new 
SIZE = 100 
SIZE.times do 
  op = rand(8)

  case op 
  when 0 
    dlist.push_front(rand(SIZE))
  when 1 
    dlist.push_back(rand(SIZE))
  when 2 
    dlist.insert_at(rand(SIZE), rand(SIZE)%10)
  when 3 
    dlist.pop_front
  when 4 
    dlist.pop_back
  when 5 
    dlist.delete_at(rand(SIZE)%10)
  when 6 
    dlist.delete_node(rand(SIZE))
  when 7 
    dlist.reverse_print_list
  end 
  dlist.print_list 
  puts
end 
