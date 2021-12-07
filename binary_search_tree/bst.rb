class Node
  attr_accessor :key, :left, :right 

  def initialize(key) 
    @key = key
    left = nil
    right = nil
  end
end

class BST 
  attr_accessor :root 

  def initialize 
    @root = nil
  end

  def insert_recur(data)
    puts "[insert_recur] inserting #{data}"
    @root = insert_recur_helper(@root, data)
  end

  def insert_iter(data)
    puts "[insert_iter] inserting #{data}"

    if @root == nil 
      @root = Node.new(data)
      return
    end

    prev = nil 
    temp = @root 

    while temp != nil 
      if data > temp.key
        prev = temp
        temp = temp.right
      elsif data < temp.key
        prev = temp
        temp = temp.left
      end
    end

    if data > prev.key
      prev.right = Node.new(data)
    else
      prev.left = Node.new(data)
    end
  end

  def delete_node(data)
    puts "[delete_node] deleting #{data}"
    @root = delete_node_helper(@root, data)
  end

  def inorder
    print "inorder: "
    inorder_helper(@root)
    puts
  end

  def preorder
    print "preorder: "
    preorder_helper(@root)
    puts
  end

  def postorder 
    print "postorder: "
    postorder_helper(@root)
    puts
  end

  def search(data)
    puts "[search] searching for #{data}"
    return true if @root == nil or @root.key == data

    prev = nil 
    curr = @root 

    while curr != nil 
      return true if curr.key == data
      if data > curr.key
        prev = curr
        curr = curr.right
      else
        prev = curr
        curr = curr.left
      end
    end
    return false
  end

  def search_recur(data)
    puts "[search_recur] searching for #{data}"
    return search_recur_helper(@root, data)
  end

  private 

  def insert_recur_helper(root, data)
    return Node.new(data) if root == nil 
  
    if data > root.key 
      root.right = insert_recur_helper(root.right, data)
    end 
    if data < root.key 
      root.left = insert_recur_helper(root.left, data)
    end

    return root
  end

  def inorder_helper(root)
    return if !root
    inorder_helper(root.left)
    print "#{root.key} "
    inorder_helper(root.right)
  end
  def preorder_helper(root)
    return if !root
    print "#{root.key} "
    inorder_helper(root.left)
    inorder_helper(root.right)
  end

  def postorder_helper(root)
    return if !root
    inorder_helper(root.left)
    inorder_helper(root.right)
    print "#{root.key} "
  end

  def search_recur_helper(root, data)
    return false if root == nil
    return true if root.key == data

    return search_recur_helper(root.left, data) if root.key > data 
    return search_recur_helper(root.right, data)
  end

  def delete_node_helper(root, data)
    return root if root == nil 

    if data < root.key 
      root.left = delete_node_helper(root.left, data)
    elsif data > root.key 
      root.right = delete_node_helper(root.right, data)
    else 
      # node has no child 
      if root.left == nil and root.right == nil 
        return nil
      # node with only one chile or no child 
      elsif root.left == nil 
        temp = root.right
        root = nil
        return temp
      elsif root.right == nil 
        temp = root.left 
        root = nil 
        return temp
      end
      
      # node with 2 children - get inorder successor
      # (smallest in the right subtree)
      temp = inorder_successor(root.right)
      root.key = temp.key 
      root.right = delete_node_helper(root.right, temp.key)
    end
    return root
  end

  def inorder_successor(node) 
    curr = node
    while curr && curr.left != nil 
      curr = curr.left
    end

    return curr
  end
end
 
bst = BST.new 
bst.insert_iter(50)
bst.insert_iter(30)
bst.insert_iter(20)
bst.insert_recur(40)
bst.insert_recur(70)
bst.insert_recur(60)
bst.insert_iter(80)
bst.inorder
bst.preorder
bst.postorder

puts

puts "#{bst.search(10)}  #{bst.search_recur(10)}"
puts "#{bst.search(50)}  #{bst.search_recur(50)}"
puts "#{bst.search(30)}  #{bst.search_recur(30)}"
puts "#{bst.search(40)}  #{bst.search_recur(40)}"
puts "#{bst.search(80)}  #{bst.search_recur(80)}"
puts "#{bst.search(70)}  #{bst.search_recur(70)}"
puts "#{bst.search(170)}  #{bst.search_recur(170)}"

puts 

bst.inorder
bst.delete_node(70)
bst.inorder

bst.delete_node(10)
bst.inorder
bst.delete_node(100)
bst.inorder
bst.delete_node(50)
bst.inorder
