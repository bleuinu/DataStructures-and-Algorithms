class Node
  attr_accessor :value, :left, :right

  def initialize(value)
    @value = value 
    @left = nil 
    @right = nil
  end 
end 

class BinaryTree
  attr_reader :root
  def initialize(value)
    @root = Node.new(value)
  end

  def insert_left(value)
    if @root.left == nil
      @root.left = Node.new(value)
    else
      new_node = Node.new(value)
      new_node.left = @root.left 
      @root.left = new_node
    end 
  end

  def insert_right(value)
    if @root.right == nil
      @root.right = Node.new(value)
    else
      new_node = Node.new(value)
      new_node.right = @root.right 
      @root.right = new_node 
    end
  end

  def preorder(node)
    return if node == nil
    puts node.root.value
    preorder(node.root.left)
    preorder(node.root.right)
  end

  def inorder(node)
    return if node == nil
    preorder(node.root.left)
    puts node.root.value
    preorder(node.root.right)
  end

  def postorder(node)
    return if node == nil
    preorder(node.root.left)
    preorder(node.root.right)
    puts node.root.value
  end

  def bfs()
    q = []
    q << self

    while !q.empty? do 
      curr = q.shift
      puts curr.root.value 

      if curr.root.left 
        q << curr.root.left 
      end
      if curr.root.right 
        q << curr.root.right 
      end
    end
  end
end

e_node = BinaryTree.new('e')

f_node = BinaryTree.new('f')

c_node = BinaryTree.new('c')
c_node.root.left = e_node 
c_node.root.right = f_node 

d_node = BinaryTree.new('d')

b_node = BinaryTree.new('b')
b_node.root.right = d_node 

a_node = BinaryTree.new('a') 
a_node.root.left = b_node 
a_node.root.right = c_node 

puts "PREORDER"
a_node.preorder(a_node)

puts "INORDER"
a_node.inorder(a_node)

puts "POSTORDER"
a_node.postorder(a_node)

puts "BFS"
a_node.bfs
