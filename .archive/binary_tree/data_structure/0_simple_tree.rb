class Node 
  attr_accessor :left, :right 

  def initialize(val)
    @data = val 
    @left = nil 
    @right = nil
  end

  def get_data
    @data
  end
end 

root = Node.new(1)
root.left = Node.new(2) 
root.right = Node.new(3) 

root.left.left = Node.new(4) 

puts "    #{root.get_data}"
puts "  #{root.left.get_data}   #{root.right.get_data}"
puts "#{root.left.left.get_data}"
