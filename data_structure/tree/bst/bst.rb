class Node
  attr_accessor :value, :left, :right, :parent
  def initialize(value)
    @value = value 
    @left = nil
    @right = nil 
    @parent = nil
  end
end

class BST
  attr_accessor :root
  def initialize(value)
    @root = Node.new(value)
    @left = nil 
    @right = nil 
    @parent = nil
  end

  def insert(value, node=@root, parent=nil)
    if value < node.value
      if node.left 
        insert(value, node.left, parent)
      else 
        node.left = Node.new(value)
        node.left.parent = (parent==nil) ? node : parent
      end
    else 
      if node.right 
        insert(value, node.right, parent) 
      else 
        node.right = Node.new(value)
        node.right.parent = (parent==nil) ? node : parent
      end
    end
  end

  def exist?(value, node=@root)
    return nil if node == nil
    return node if node.value == value 

    if value > node.value
      exist?(value, node.right)
    else
      exist?(value, node.left)
    end
  end

  def find_min(node)
    return node if node.left == nil
    find_min(node.left)
  end

  def delete(value)
    node = exist? value
    return nil if node == nil

    if node.left == nil and node.right == nil 
      # scenario 1
      (node.parent.left == node) ? node.parent.left = nil : node.parent.right = nil
    elsif node.left && node.right
      # scenario 3
      min = node.right
      x = find_min(node.right)
      min = x if x != nil

      if x != nil
        node.value = min.value
      end

      min.parent.left = nil if min.parent.left == min 
      min.parent.right = nil if min.parent.right == min 

    else 
      # scenario 2
      if node.parent.left == node 
        if node.left 
          node.left.parent = node.parent
          node.parent.left = node.left
        else 
          node.right.parent = node.parent
          node.parent.left = node.right
        end
      else
        if node.left 
          node.left.parent = node.parent
          node.parent.right = node.left
        else 
          node.right.parent = node.parent
          node.parent.right = node.right
        end
      end
    end
  end

  def dfs
    dfs_helper(@root)
  end

  def dfs_helper(node)
    return if node==nil 

    puts node.value
    dfs_helper(node.left)
    dfs_helper(node.right)
  end
end

bst = BST.new(15)
bst.insert(10)
bst.insert(8)
bst.insert(12)
bst.insert(20)
bst.insert(17)
bst.insert(25)
bst.insert(19)
bst.dfs
puts

puts "delete 8"
bst.delete(8)
bst.dfs
puts

puts "delete 17"
bst.delete(17)
bst.dfs
puts

puts "delete 15"
bst.delete(15)
bst.dfs
puts
