class Stack
  def initialize (size)
    @capacity = size
    @stack = Array.new(@capacity)
    @size = 0
  end

  def push (data)
    if @size == @capacity
      puts "The stack is full. Stack resized (#{@capacity} -> #{@capacity * 2})"
      @capacity *= 2
    end

    @stack[@size] = data
    @size += 1
  end

  def pop
    if @size==0
      puts "The stack is empty.."
      return nil
    end

    @size -= 1
    val = @stack.fetch(@size)
  end

  def top
    if @size==0
      puts "The stack is empty.."
      return nil
    end

    @stack.fetch(@size-1)
  end

  def empty?
    @size==0
  end

  def show
    if @size == 0
      puts "The stack is empty.."
      return nil
    end

    0.upto(@size-1) { |i| print "#{@stack.fetch(i)} " }
    puts
  end
end

print "Initial size: "
size = gets.to_i
stack = Stack.new(size)

while true do
  puts "0. exit"
  puts "1. push        2. pop        3. show        4. top"
  print"> "
  c = gets.to_i

  break if c == 0

  case c
  when 1
    print "push: "
    stack.push(gets.to_i)
  when 2
    stack.pop
  when 3
    stack.show
  when 4
    puts "top of the stack: #{stack.top}"
  end
  puts
end
