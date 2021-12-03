class Queue
  def initialize 
    @queue = []
  end

  def enqueue(data)
    @queue << data 
  end

  def dequeue
    if is_empty?
      puts "queue is empty.."
    else
      @queue.shift
    end
  end

  def is_empty? 
    return @queue.size == 0
  end

  def display 
    print " front | "
    @queue.each do |data|
      print "#{data} "
    end
    puts "| back"
  end
end

=begin
queue = Queue.new 
queue.enqueue(1)
queue.display

queue.enqueue(2)
queue.display

queue.enqueue(3)
queue.display

puts queue.dequeue
queue.display

puts queue.dequeue
queue.display
puts queue.dequeue
queue.display
=end
