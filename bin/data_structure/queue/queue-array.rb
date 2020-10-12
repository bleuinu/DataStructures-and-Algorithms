class Queue
  def initialize (size)
    @capacity = size
    @queue = Array.new(@capacity)
    @size = 0
  end

  def enqueue (data)
    if @size == @capacity
      puts "The queue is full. Resizing the queue (#{@capacity} -> #{@capacity * 2})"
      @capacity <<= 1
    end

    @queue[@size] = data
    @size += 1
  end

  def dequeue
    if @size == 0
      puts "The queue is empty.."
      return nil
    end

    val = @queue[0]
    @queue.shift()
    @size -= 1
    val
  end

  def print_queue
    print "FRONT--| "
    curr = @rear
    0.upto(@size-2) do |i|
      print "#{@queue.fetch(i)} -> "
    end
    puts "#{@queue.fetch(@size-1)} |--REAR"
  end

  def empty?
    @size == 0
  end

  def front
    if @size == 0
      puts "The queue is empty.."
      return nil
    end

    @queue[0]
  end
end

print "Initial size for the Queue: "
size = gets.to_i
q = Queue.new(size)

while true do
  puts "0. exit"
  puts "1. enqueue        2. dequeue        3. show        4. front"
  print"> "
  c = gets.to_i

  break if c == 0

  case c
  when 1
    print "enqueue: "
    q.enqueue(gets.to_i)
  when 2
    q.dequeue
  when 3
    q.print_queue
  when 4
    puts "front of the q: #{q.front}"
  end
  puts
end
