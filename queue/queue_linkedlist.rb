class Node 
  attr_accessor :next, :prev, :data

  def initialize(data)
    @data = data 
    @next = nil
    @prev = nil
  end
end

class Queue 
  def initialize(data = nil)
    if data == nil
      @head = nil 
      @tail = nil
      @capacity = 0
    else 
      @head = Node.new(data)
      @tail = @head
      @capacity = 1
    end
  end

  def enqueue(data)
    puts "[enqueue] enqueue #{data}"
    if is_empty?
      @head = Node.new(data)
      @tail = @head 
      @head.next = @tail 
      @tail.prev = @head
    else 
      new_node = Node.new(data)
      @tail.next = new_node 
      new_node.prev = @tail 
      @tail = new_node
    end
    @capacity += 1
  end 

  def dequeue
    puts "[dequeue] inside dequeue method"
    if is_empty? 
      puts "[dequeue] queue is empty.."
      return nil 
    else 
      curr = @head 
      @head = @head.next 
      @capacity -= 1
      return curr.data
    end 
  end

  def is_empty? 
    return @capacity == 0
  end

  def rear 
    return @tail.data
  end

  def display 
    print "front | "

    curr = @head
    (@capacity).times do 
      print "#{curr.data} "
      curr = curr.next
    end

    puts "| back"
  end
end

=begin
queue = Queue.new 
queue.enqueue(10)
queue.enqueue(20)
queue.enqueue(30)
queue.enqueue(40)
queue.dequeue
queue.display

puts queue.rear
=end
