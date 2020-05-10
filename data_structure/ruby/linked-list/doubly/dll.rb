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

  def insert_front(value)
    new_node = Node.new(value)
    new_node.next = @head
    new_node.prev = nil

    if @head != nil
      @head.prev = new_node
      new_node.next = @head
      @head = new_node
    else
      @head = new_node
      @tail = @head
    end

    @length += 1
  end

  def insert_back(value)
    new_node = Node.new(value)
    new_node.next = nil
    new_node.prev = @tail

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

  # position 1 == first node
  def insert_at(value, pos)
    if pos <= 1
      insert_front(value)
    elsif pos >= @length
      insert_back(value)
    else
      new_node = Node.new(value)
      curr = get_node_at(pos-1)
      insert_after(curr, value)
    end
  end

  # position 1 == first node
  def get_node_at(pos)
    return nil if pos < 1 or pos > @length
    return get_head_node if pos == 1
    return get_tail_node if pos == @length

    curr = @head
    for i in 1...pos
      curr = curr.next
    end

    curr
  end

  def insert_after(node, value)
    return nil if node == nil
    return insert_back(value) if node == @tail

    new_node = Node.new(value)
    new_node.next = node.next
    new_node.prev = node
    node.next.prev = new_node
    node.next = new_node

    @length += 1
  end

  def insert_before(node, value)
    return nil if node == nil
    return insert_front(value) if node == @head

    new_node = Node.new(value)
    new_node.next = node
    new_node.prev = node.prev
    node.prev.next = new_node
    node.prev = new_node

    @length += 1
  end

  def remove_at(pos)
    pos = 1 if pos <= 1
    pos = @length if pos >= @length

    if pos == 1
      data = @head.data
      @head = @head.next
      @head.prev = nil if @head
    elsif  pos == @length
      data = @tail.data
      @tail = @tail.prev
      @tail.next = nil if @tail
    else
      curr = get_node_at(pos)
      data = curr.data

      curr.prev.next = curr.next
      curr.next.prev = curr.prev
      curr = nil
    end

    @length -= 1
    return data
  end

  def get_head_node()
    return @head
  end

  def get_tail_node()
    return @tail
  end

  def length()
    @length
  end

  def print_list(reverse = false)
    curr = reverse ? @tail : @head
    for i in 0...@length
      print "#{curr.data} "
      curr = reverse ? curr.prev : curr.next
    end
    puts
  end
end

list = DoublyLinkedList.new()
0.upto(3) {|x| list.insert_front(x)}
list.print_list()

4.upto(7) {|x| list.insert_back(x)}
list.print_list()

list.insert_at(50, 5)
list.print_list

list.insert_before(list.get_head_node(), 77)
list.insert_after(list.get_tail_node(), 77)
list.print_list
list.print_list true

while list.length > 0
  puts "deleted value: #{list.remove_at(list.length/2)}"
end

