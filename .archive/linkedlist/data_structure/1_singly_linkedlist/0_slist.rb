class Node 
  attr_accessor :next 
  attr_reader :data

  def initialize(data) 
    @data = data 
    @next = nil
  end 
end 

class SinglyLinkedList
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
    if @head == nil
      @head = new_node
    else 
      new_node.next = @head 
      @head = new_node
    end 

    @node_count += 1
  end 

  def push_back(data)
    puts "[push_back] inserting #{data}"
    if @head == nil 
      @head = Node.new(data) 
    else 
      temp = @head 
      while temp.next != nil 
        temp = temp.next 
      end 
      
      temp.next = Node.new(data)
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
      temp = @head
      (idx-1).times { temp = temp.next }
      new_node = Node.new(data)
      new_node.next = temp.next 
      temp.next = new_node 

      @node_count += 1
    end 
  end 

  def pop_front
    if @node_count == 0 
      puts "[pop_front] no more nodes to pop"
    else 
      data = @head.data 
      @head = @head.next
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
      temp = @head 
      (@node_count-2).times { temp = temp.next }
      data = temp.next.data
      temp.next = nil 
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
      elsif idx >= @node_count
        puts "  [delete_at] idx >= node_count(#{@node_count})... call pop_back"
        pop_back 
      else 
        temp = @head 
        (idx-1).times { temp = temp.next }
        temp.next = temp.next.next
        @node_count -= 1
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
    temp = @head 
    while temp do 
      print "#{temp.data} "
      temp = temp.next
    end 
    puts
  end 
end 

=begin
slist = SinglyLinkedList.new 
SIZE = 100 
SIZE.times do 
  op = rand(7)

  case op 
  when 0 
    slist.push_front(rand(SIZE))
  when 1 
    slist.push_back(rand(SIZE))
  when 2 
    slist.insert_at(rand(SIZE), rand(SIZE)%10)
  when 3 
    slist.pop_front
  when 4 
    slist.pop_back
  when 5 
    slist.delete_at(rand(SIZE)%10)
  when 6 
    slist.delete_node(rand(SIZE))
  end 
  slist.print_list 
  puts
end 
=end
