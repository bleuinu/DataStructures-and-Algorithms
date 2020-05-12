class Node
  attr_accessor :data, :left, :right

  def initialize(data, left=nil, right=nil)
    @data = data
    @left = left
    @right = right
  end
end

class BST
  def initialize(data=nil)
    @root = (data == nil) ? nil : Node.new(data)
  end

  def insert(data)
    if @root == nil
      @root = Node.new(data)
    else
      curr = @root
      parent = nil

      while true
        parent = curr

        if data < parent.data
          curr = curr.left

          if curr == nil
            parent.left = Node.new(data)
            return
          end
        else
          curr = curr.right

          if curr == nil
            parent.right = Node.new(data)
            return
          end
        end
      end
    end
  end

  def search(data)
    return @root if @root.data == data
    curr = @root

    while true
      if data > curr.data
        curr = curr.right
      else
        curr = curr.left
      end
      
      return curr if curr == nil or curr.data == data
    end
  end

  def traverse(order)
    if order == "inorder"
      inorder(@root)
    elsif order == "preorder"
      preorder(@root)
    else
      postorder(@root)
    end
    puts
  end

  def inorder(node)
    return if node == nil

    inorder(node.left)
    print "#{node.data} "
    inorder(node.right)
  end

  def preorder(node)
    return if node == nil

    print "#{node.data} "
    preorder(node.left)
    preorder(node.right)
  end

  def postorder(node)
    return if node == nil

    postorder(node.left)
    postorder(node.right)
    print "#{node.data} "
  end
end

=begin
     d
   /   \ 
  b     f
 / \   / \ 
a     e   g
=end
tree = BST.new()
tree.insert('d')
tree.insert('b')
tree.insert('a')
tree.insert('c')
tree.insert('f')
tree.insert('e')
tree.insert('g')

tree.traverse("inorder")
tree.traverse("preorder")
tree.traverse("postorder")
