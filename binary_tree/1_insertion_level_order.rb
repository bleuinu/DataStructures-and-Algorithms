class Node
  attr_accessor :left, :right, :data

  def initialize(val)
    @data = val
    @left = nil 
    @right = nil
  end
end

def create_node(val)
  return Node.new(val)
end

def insert_node(root, val)
  if root == nil 
    root = create_node(val)
    return root
  end

  q = [root]
  while !q.empty?
    temp = q.shift

    if temp.left != nil
      q.push(temp.left)
    else 
      temp.left = Node.new(val)
      return root
    end 

    if temp.right != nil 
      q.push(temp.right)
    else 
      temp.right = Node.new(val)
      return root 
    end
  end
end

def inorder(root)
  return if root == nil 
  inorder(root.left)
  print "#{root.data} "
  inorder(root.right)
end

root = create_node(10)
root.left = create_node(11)
root.left.left = create_node(7)
root.right = create_node(9)
root.right.left = create_node(15)
root.right.right = create_node(8)

print "Inorder traversal before insertion: "
inorder(root)
puts 

key = 12
root = insert_node(root, key)

print "Inorder traversal after insertion: "
inorder(root)
puts
