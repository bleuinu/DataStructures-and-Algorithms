# Linked list Queue Implementation
class Node
  attr_accessor :next, :data

  def initialize(data)
    @data = data
    @next = nil
  end
end

class Queue
  def initialize
    @front = nil
    @rear = nil
    @size = 0
  end

  def enqueue(data)
    new_node = Node.new(data)

    # rear |- - - - -| front
    if @size == 0
      @rear = @front = new_node
      @rear.next = @front
    else
      new_node.next = @rear
      @rear = new_node
    end

    puts "enqueue #{data}"
    @size += 1
  end

  def dequeue
    data = @front.data

    curr = @rear
    while curr.next != @front
      curr = curr.next
    end
    curr.next = nil
    @front = curr

    puts "dequeue #{data}"
    @size -= 1
  end

  def front
    @front.data
  end

  def rear
    @rear.data
  end

  def print_queue
    print "REAR--| "
    curr = @rear
    while curr != @front
      print "#{curr.data} -> "
      curr = curr.next
    end
    puts "#{@front.data} |--FRONT"
  end
end

q = Queue.new()
1.upto(10) do |x|
  q.enqueue(x)
end
q.print_queue

q.dequeue
q.dequeue
q.dequeue
q.dequeue
q.dequeue
q.print_queue

q.enqueue 100
q.print_queue

puts q.front
puts q.rear
