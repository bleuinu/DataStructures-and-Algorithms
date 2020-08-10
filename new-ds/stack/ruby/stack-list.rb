# Linked List based stack implementation
class Node
  attr_accessor :next, :data

  def initialize(data)
    @data = data
    @next = nil
  end
end

class Stack
  def initialize
    @top = nil
    @size = 0
  end

  def push(data)
    new_node = Node.new(data)

    if @top == nil
      @top = new_node
    else
      new_node.next = @top
      @top = new_node
    end

    puts "push #{data}"
    @size += 1
  end

  def pop
    if is_empty?
      puts "Underflow.."
    else
      data = @top.data
      puts "pop #{data}"
      @top = @top.next
      @size -= 1
    end
  end

  def top
    @top.data
  end

  def is_empty?
    @size == 0
  end

  def print_stack
    curr = @top
    while curr.next != nil
      print "#{curr.data} -> "
      curr = curr.next
    end
    puts curr.data
  end
end

stack = Stack.new()
stack.push(1)
stack.push(2)
puts "stack is empty? #{stack.is_empty?}"
stack.print_stack

stack.pop
stack.pop

puts "stack is empty? #{stack.is_empty?}"

stack.push(3)
puts stack.top
puts "stack is empty? #{stack.is_empty?}"

stack.pop
