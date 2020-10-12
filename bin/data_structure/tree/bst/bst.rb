class Node 
  attr_accessor :left, :right, :data

  def initialize(data, left=nil, right=nil) 
    @left = left 
    @right = right 
    @data = data
  end
end

class BinaryTree 
  def initialize(data)
    @root  = Node.new(data)
  end

  def insert(data) 
    @root = insertRecursive(@root, data)
  end

  def insertRecursive(node, data) 
    return Node.new(data) if (node == nil) 

    if data > node.data 
      node.right = insertRecursive(node.right, data)
    elsif data < node.data
      node.left = insertRecursive(node.left, data) 
    else 
      return node 
    end

    return node
  end

  def find_min(node)
    return node.data if node.left == nil
    find_min(node.left)
  end

  def delete(data) 
    @root = deleteRecursive(@root, data)
  end

  def deleteRecursive(curr, data) 
    return nil if curr == nil 
  
    if data == curr.data 
      return nil if curr.left == nil and curr.right == nil 
      return curr.left if curr.right == nil  
      return curr.right if curr.left == nil 

      smallest_data = find_min(curr.right)
      curr.data = smallest_data  
      curr.right = deleteRecursive(curr.right, smallest_data) 
      return curr
    end

    if data < curr.data
      curr.left = deleteRecursive(curr.left, data)
      return curr
    end

    curr.right = deleteRecursive(curr.right, data) 
    return curr
  end

  def search(value) 
    node = @root 

    while true 
      return nil if node == nil 
      return node if node.data == value

      if value > node.data 
        node = node.right
      else 
        node = node.left
      end
    end
  end

  def preorder(node = @root)
    return if (node == nil) 
    print "#{node.data} "
    preorder(node.left)
    preorder(node.right)
  end

  def inorder(node = @root) 
    return if node == nil 
    inorder(node.left)
    print "#{node.data} "
    inorder(node.right)
  end

  def postorder(node = @root) 
    return if node == nil 
    postorder(node.left)
    postorder(node.right)
    print "#{node.data} "
  end

  def bfs
    return nil if @root == nil
    q = [@root]

    while !q.empty? 
      neighbor = q.shift
      print "#{neighbor.data} "

      (q << neighbor.left) if neighbor.left != nil 
      (q << neighbor.right) if neighbor.right != nil 
    end
  end
end

tree = BinaryTree.new(6)
tree.insert(4)
tree.insert(8)
tree.insert(3)
tree.insert(5)
tree.insert(7)
tree.insert(9)

print "Preorder: " 
tree.preorder
puts

print "Inorder: "
tree.inorder 
puts

print "Postorder: "
tree.postorder
puts

print "BFS: " 
tree.bfs 
puts

print "Search 5: #{!!tree.search(5)}"
puts
print "Search 2: #{!!tree.search(2)}"
puts
print "Search 1: #{!!tree.search(1)}"
puts
print "Search 9: #{!!tree.search(9)}"
puts
puts

puts "Delete 5"
tree.delete(5)
print "DFS: " 
tree.preorder
puts

puts "Delete 4"
tree.delete(4)
print "DFS: " 
tree.preorder
puts

puts "Delete 8"
tree.delete(8)
print "DFS: " 
tree.preorder
puts

puts "Delete 6"
tree.delete(6)
print "DFS: " 
tree.preorder 
puts

puts "Delete 7"
tree.delete(7)
print "DFS: " 
tree.preorder 
puts

puts "Delete 9"
tree.delete(9)
print "DFS: " 
tree.preorder 
puts

puts "Delete 3"
tree.delete(3)
print "DFS: " 
tree.preorder 
puts
