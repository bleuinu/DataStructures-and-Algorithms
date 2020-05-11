# Circular Doubly Linked List
class Node
  attr_accessor :data, :prev, :next

  def initialize(data, prev=nil,_next=nil)
    @data = data
    @prev = prev
    @next = _next
  end
end

class CircularDLL
  def initialize()
    @head = nil
    @length = 0
  end

  def insert_front(value)
    new_node = Node.new(value)

    if @length == 0
      new_node.next = new_node.prev = new_node
      @head = new_node
    else
      new_node.next = @head
      new_node.prev = @head.prev
      @head.prev.next = @head.prev = new_node
      @head = new_node
    end

    @length += 1
  end

  def insert_back(value)
    new_node = Node.new(value)

    if @length == 0
      new_node.next = new_node.prev = new_node
      @head = new_node
    else
      new_node.next = @head
      new_node.prev = @head.prev
      @head.prev.next = @head.prev = new_node
    end

    @length += 1
  end

  # position 1 = first node
  def insert_at(value, pos)
    return insert_front(value) if pos <= 1
    return insert_last(value) if pos >= @length

    curr = @head
    for i in 1...pos
      curr = curr.next
    end

    new_node = Node.new(value)
    new_node.next = curr
    new_node.prev = curr.prev
    curr.prev.next = curr.prev = new_node

    @length += 1
  end

  def remove_front()
    return if @length == 0
    if @head.next == @head
      @head = nil
      @length = 0
      return
    end

    @head.next.prev = @head.prev
    @head.prev.next = @head.next
    @head = @head.next
    @length -= 1
  end

  def remove_back()
    return if @length == 0

    if @head.next == @head
      @head = nil
      @length = 0
      return nil
    end

    @head.prev.prev.next = @head
    @head.prev = @head.prev.prev
    @length -= 1
  end

  # position 1 = first node
  def remove_at(pos)
    return if @length == 0
    return remove_front if pos <= 1
    return remove_back if pos >= @length

    curr = @head
    for i in 1...pos
      curr = curr.next
    end

    curr.prev.next = curr.next
    curr.next.prev = curr.prev

    @length -= 1
  end

  def get_first_node()
    @head
  end

  def get_last_node()
    @head.prev
  end

  def length()
    @length
  end

  def print_list()
    puts "Length: #{@length}"
    return if @length == 0

    curr = @head
    while curr != @head.prev
      print "#{curr.data} "
      curr = curr.next
    end
    puts curr.data
  end

  def traverse_from(node)
    puts "Length: #{@length}"
    return if @length == 0

    start = node
    curr = node
    while curr.next != start
      print "#{curr.data} "
      curr = curr.next
    end
    puts curr.data
  end
end

list = CircularDLL.new()
4.downto(1) {|x| list.insert_front(x)}
list.print_list
5.upto(10) {|x| list.insert_back(x)}
list.print_list

list.insert_at(77, 5)
list.print_list

while list.length > 0
  list.print_list
  list.remove_at(list.length / 2)
end
list.print_list
