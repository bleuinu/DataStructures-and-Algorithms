# PQueue using Linked Lists

class Node
  attr_accessor :data, :priority, :next

  def initialize(data, priority)
    @data = data
    @priority = priority
    @next = nil
  end
end

class PQueue
  def initialize
    @root = nil
  end

  def push(data, priority)
    new_node = Node.new(data, priority)

    if @root == nil
      @root = new_node
    elsif @root.priority < priority
      new_node.next = @root
      @root = new_node
    else
      # traverse the list and find the proper position
      curr = @root
      while curr.next != nil and curr.next.priority < priority
        curr = curr.next
      end

      new_node.next = curr.next
      curr.next = new_node
    end
  end

  # removes the highest priority element
  def pop
    return if @root == nil
    data = @root.data
    @root = @root.next

    puts "pop #{data}"
    data
  end

  # get highest priority element
  def peek
    @root.data
  end

  def is_empty?
    return @root==nil
  end

  def print_list
    return if @root == nil
    curr = @root
    while curr.next != nil
      print "(#{curr.data}, #{curr.priority}) -> "
      curr = curr.next
    end
    puts "(#{curr.data}, #{curr.priority})"
  end
end

pq = PQueue.new()
0.upto(5) do |x|
  pq.push((97+x).chr, 97+x)
  pq.print_list
  puts
end

pq.pop
pq.print_list
pq.pop
pq.print_list
pq.pop
pq.print_list
pq.pop
pq.print_list
pq.pop
pq.print_list
pq.pop
pq.print_list
pq.pop
pq.print_list
