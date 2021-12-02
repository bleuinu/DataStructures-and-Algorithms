class Stack 
  def initialize
    @stack = []
  end

  def push(data)
    @stack.push(data)
  end 

  def pop 
    @stack.pop
  end 

  def top 
    @stack.last
  end 

  def display 
    print " base | "
    if is_empty? 
      print "[EMPTY]"
    else 
      size = @stack.size

      (size-1).times { |i| print "#{@stack[i]} - "}
    end
    puts "#{@stack.last} | top "
  end

  def is_empty? 
    @stack.size == 0
  end 
end 

=begin
stack = Stack.new 
stack.push(1)
stack.push(2)
stack.push(3) 
stack.display

stack.pop
stack.display

stack.pop
stack.display

stack.pop
stack.display

stack.push(7)
stack.display
puts stack.top

stack.push(77)
stack.display
puts stack.top

stack.push(777)
stack.display
puts stack.top
=end
