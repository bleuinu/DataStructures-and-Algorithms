# Circular Singly Linked List
class Node
  attr_accessor :data, :next

  def initialize(data, _next=nil)
    @data = data
    @next = _next
  end
end

class CircularSLL
  def initialize()
    @last = nil
    @length = 0
  end

  def insert_front(value)
    new_node = Node.new(value)

    if @last == nil
      @last = new_node
      @last.next = @last
    else
      new_node.next = @last.next
      @last.next = new_node
    end

    @length += 1
  end

  def insert_back(value)
    new_node = Node.new(value)

    if @last == nil
      @last = new_node
      @last.next = @last
    else
      new_node.next = @last.next
      @last.next = new_node
      @last = new_node
    end

    @length += 1
  end

  # position 1 = first node
  def insert_at(value, pos)
    return insert_front(value) if pos <= 1
    return insert_last(value) if pos >= @length

    curr = @last
    for i in 1...pos
      curr = curr.next
    end

    new_node = Node.new(value)
    new_node.next = curr.next
    curr.next = new_node

    @length += 1
  end

  # position 1 = first node
  def remove_at(pos)
    return if @length == 0
    return remove_front if pos <= 1
    return remove_back if pos >= @length

    curr = @last
    for i in 1...pos
      curr = curr.next
    end

    curr.next = curr.next.next

    @length -= 1
  end

  def remove_front()
    return if @length == 0
    if @last.next == @last
      @last = nil
      @length = 0
      return
    end

    @last.next = @last.next.next
    @length -= 1
  end

  def remove_back()
    return if @length == 0
    if @last.next == @last
      @last = nil
      @length = 0
      return
    end

    curr = @last.next
    while curr.next != @last
      curr = curr.next
    end

    curr.next = @last.next
    @last = curr
    
    @length -= 1
  end

  def find_node_by_value(value)
    return @last if @last.data == value

    curr = @last.next
    while curr != @last
      return curr if curr.data == value
      curr = curr.next
    end

    return nil
  end

  def get_first_node()
    @last.next
  end

  def get_last_node()
    @last
  end

  def length()
    @length
  end

  def print_list()
    puts "Length: #{@length}"
    return if @length == 0

    curr = @last.next
    while curr != @last
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

list = CircularSLL.new()

5.upto(10) { |x| list.insert_back(x) }
4.downto(1) { |x| list.insert_front(x) }
list.print_list
list.traverse_from(list.find_node_by_value(9))
list.traverse_from(list.find_node_by_value(5))
