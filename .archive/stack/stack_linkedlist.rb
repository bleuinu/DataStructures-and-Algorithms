require '../linkedlist/03-circular-doubly-linkedlist/0-cdlist.rb'

class CircularLinkedList 
  def get_tail
    @tail.data
  end
end

class Stack 
  def initialize(data = nil)
    @stack = CircularLinkedList.new(data)
  end

  def push(data)
    @stack.push_back(data)
  end 

  def pop 
    if is_empty? 
      puts "stack is empty.."
    else 
      @stack.pop_back
    end
  end 

  def top 
    if is_empty? 
      puts "stack is empty.."
    else 
      puts "[top] of the stack: #{@stack.get_tail}"
    end
  end 

  def display
    if is_empty? 
      puts "stack is empty.."
    else 
      @stack.print_list
    end
  end

  def is_empty? 
    @stack.node_count == 0
  end 
end 

=begin
stack = Stack.new 
puts stack.top
stack.push(1)
puts stack.top
stack.push(2)
puts stack.top
stack.push(3)
puts stack.top

stack.pop 
stack.pop 
stack.display 

stack.pop 
stack.display 
=end
