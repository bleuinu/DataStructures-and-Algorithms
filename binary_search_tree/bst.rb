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
    @root = insert_recur_helper(@root, data)
  end

  def insert_iter(data)
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
