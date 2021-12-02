class Node 
  attr_accessor :next, :prev 
  attr_reader :data

  def initialize(data) 
    @data = data 
    @next = nil
    @prev = nil
  end 
end 

class CircularLinkedList
  attr_accessor :tail 
  attr_reader :node_count

  def initialize(data = nil)
    if data != nil 
    puts "[initialize] data = #{data}"
      @tail = Node.new(data)
      @node_count = 1
    else 
      puts "[initialize] data = nil"
      @tail = nil 
      @node_count = 0
    end 
  end 

  def push_front(data)
    puts "[push_front] inserting #{data} "
    new_node = Node.new(data)
    if @tail == nil 
      @tail = new_node 
      @tail.next = @tail 
      @tail.prev = @tail 
    else 
      head = @tail.next 
      new_node.next = head 
      new_node.prev = @tail 
      head.prev = new_node 
      @tail.next = new_node 
    end 

    @node_count += 1
  end 

  def push_back(data)
    puts "[push_back] inserting #{data}"
    new_node = Node.new(data)
    if @tail == nil 
      @tail = new_node
      @tail.next = @tail 
      @tail.prev = @tail 
    else 
      new_node.prev = @tail 
      new_node.next = @tail.next 
      @tail.next = new_node
      @tail = new_node
    end 

    @node_count += 1
  end 

  # index = zero-based
  def insert_at(data, idx) 
    puts "[insert_at] insert #{data} at #{idx}"
    if idx <= 0
      puts "  index is <= 0"
      push_front(data)
    elsif idx >= (@node_count - 1)
      puts "  index is >= node_count(#{@node_count})"
      push_back(data)
    else 
      curr = @tail.next
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
    elsif @node_count == 1 
      data = @tail.data 
      @tail = nil 
      @node_count = 0 
      puts "[pop_front] pop #{data}"
      return data 
    else 
      data = @tail.next.data 
      head = @tail.next 
      @tail.next = head.next
      head.next.prev = @tail 
      head = nil
      @node_count -= 1 

      puts "[pop_front] pop #{data}"
      return data 
    end
  end 

  def pop_back 
    if @node_count == 0 
      puts "[pop_back] no more nodes to pop"
    elsif @node_count == 1 
      data = @tail.data 
      @tail = nil 
      @node_count = 0 
      puts "[pop_back] pop #{data}"
      return data 
    else 
      curr = @tail 
      data = curr.data
      @tail.prev.next = @tail.next 
      @tail.next.prev = @tail.prev 
      temp = @tail 
      @tail = @tail.prev
      temp = nil
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
        curr = @tail.next
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
    return nil if @node_count == 0
    curr = @tail.next 
    index = 0
    while curr != @tail
      return index if curr.data == data
      curr = curr.next 
      index += 1
    end 
    return nil 
  end 

  def print_list
    puts "[Print List]"
    return if @node_count == 0
    curr = @tail.next
    (@node_count-1).times do 
      print "#{curr.data} - "
      curr = curr.next
    end 
    puts "#{curr.data}" if curr
  end 

  def reverse_print_list 
    puts "[Reverse Print List]"
    return if @node_count == 0

    curr = @tail
    (@node_count-1).times do
      print "#{curr.data} - "
      curr = curr.prev
    end
    puts "#{curr.data}" if curr
  end 
end 

=begin
clist = CircularLinkedList.new 
SIZE = 100
SIZE.times do 
  op = rand(8)

  case op 
  when 0 
    clist.push_front(rand(SIZE))
  when 1 
    clist.push_back(rand(SIZE))
  when 2 
    clist.insert_at(rand(SIZE), rand(SIZE)%10)
  when 3 
    clist.pop_front
  when 4 
    clist.pop_back
  when 5 
    clist.delete_at(rand(SIZE)%10)
  when 6 
    clist.delete_node(rand(SIZE))
  when 7 
    clist.reverse_print_list
  end 
  clist.print_list 
  puts
end 
=end
