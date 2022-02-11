=begin
  Algorithm 
  1. Starting at the root, find the deepest and rightmost node in binary tree and node which we want to delete. 
  2. Replace the deepest rightmost node’s data with the node to be deleted. 
  3. Then delete the deepest rightmost node.
=end

class Node
  attr_accessor :left, :right, :key

  def initialize(key)
    @key = key 
    @left = nil 
    @right = nil
  end
end

def inorder(node)
  return nil if !node 

  inorder(node.left)
  print "#{node.key} "
  inorder(node.right)
end

def deletion(root, key)
  return nil if root == nil

  if root.left == nil and root.right == nil 
    if root.key == key 
      return nil 
    else 
      return root 
    end
  end 

  key_node = nil
  last = nil
  temp = nil
  q = [root]

  while !q.empty?
    temp = q.shift 

    if temp.key == key 
      key_node = temp 
    end

    if temp.left 
      last = temp
      q.push(temp.left)
    end 

    if temp.right 
      last = temp
      q.push(temp.right)
    end
  end

  if key_node != nil  
    key_node.key = temp.key

    if last.right == temp 
      last.right = nil 
    else 
      last.left = nil
    end

    temp = nil
  end

  return root
end

root = Node.new(10)
root.left = Node.new(11)
root.left.left = Node.new(7)
root.left.right = Node.new(12)

root.right = Node.new(9)
root.right.left = Node.new(15)
root.right.right = Node.new(8)

print "Inorder traversal before deletion: "
inorder(root)
puts 

key = 11
root = deletion(root, key)

print "Inorder traversal after deletion: "
inorder(root)
puts
