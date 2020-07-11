class Node
  attr_accessor :data, :prev, :next

  def initialize(data, prev=nil, _next=nil)
    @data = data
    @prev = prev
    @next = _next
  end
end

class DoublyLinkedList

  def initialize()
    @head = @tail = nil
    @length = 0
  end

  def insert(value)
    new_node = Node.new(value, @tail)

    if @tail != nil
      @tail.next = new_node
      new_node.prev = @tail
      @tail = new_node
    else
      @tail = new_node
      @head = @tail
    end

    @length += 1
  end

  def insert_at(index, value)
    if index < 0 or index > @length
      puts "... failed to insert #{value} at index #{index}"
      return nil
    elsif index == 0
      new_node = Node.new(value, nil, @head)

      if @head != nil
        @head.prev = new_node
        new_node.next = @head
        @head = new_node
      else
        @head = new_node
        @tail = @head
      end
    else
      new_node = Node.new(value)
      curr = get_node_at(index-1)

      new_node.next = curr.next
      new_node.prev = curr
      curr.next.prev = new_node
      curr.next = new_node
    end

    @length += 1
  end

  def get_node_at(index)
    return nil if index < 0 or index >= @length
    return @head if index == 0
    return @tail if index+1 == @length

    curr = @head
    for i in 0...index
      curr = curr.next
    end

    curr
  end

  def remove_at(index)
    if index < 0 or index >= @length
      puts ".. failed to remove a node at #{index}"
      return nil
    end

    if index == 0
      data = @head.data
      @head = @head.next
      @head.prev = nil if @head
    elsif  index == @length-1
      data = @tail.data
      @tail = @tail.prev
      @tail.next = nil if @tail
    else
      curr = get_node_at(index)
      data = curr.data

      curr.prev.next = curr.next
      curr.next.prev = curr.prev
      curr = nil
    end

    @length -= 1
    return data
  end

  def search(data)
    curr = @head
    for i in 0...@length
      # data found 
      if curr.data == data
        puts "'#{data}' is located at index '#{i}'"
        return i
      end
      curr = curr.next
    end

    puts "'#{data}' is not in the list"
    return false
  end

  def length()
    @length
  end

  def print_list
    curr = @head
    for i in 0...@length-1
      print "#{curr.data} -> "
      curr = curr.next
    end
    puts "#{curr.data}"
  end
end

list = DoublyLinkedList.new()
puts "Insert 1 to 5 at index 0"
1.upto(5) do |i|
  list.insert_at(0,i)
end
list.print_list

puts "insert 0 at the front"
list.insert_at(0, 0)
list.print_list

puts "insert 6 to 10 at the back"
6.upto(10) do |i|
  list.insert(i)
end
list.print_list

puts "insert 100 at index 5"
list.insert_at(5, 100)
list.print_list

puts "remove a node at index 3"
list.remove_at(3)
list.print_list

puts "print list's size"
puts list.length

puts "search for the data '6'"
list.search(6)

puts "search for the data '77'"
list.search(77)
