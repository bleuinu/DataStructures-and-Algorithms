# Circular Linked List

module CircularLinkedList
  class Singly
    class Node
      attr_accessor :data, :next     

      def initialize(data, _next=nil)
        @data = data
        @next = _next
      end
    end

    # constructor
    def initialize
      @last = nil
      @length = 0
    end

    # inserts a node at the end
    def insert(data)
      new_node = Node.new(data)

      if @last == nil
        @last = new_node
        @last.next = @last
      else
        new_node.next = @last.next
        @last.next = new_node
        @last = new_node
      end

      @length += 1
    end

    # inserts a node at 'index'
    def insert_at(index, data)
      if index < 0 or index > @length
        # out of bounds
        puts ".. cannot insert '#{data}' at index #{index}"
      elsif @length == 0 or index == @length
        # insert at the back
        insert(data)
      elsif index == 0
        # insert at the front
        new_node = Node.new(data)
        
        new_node.next = @last.next
        @last.next = new_node
        
        @length += 1
      else
        # insert in between
        new_node = Node.new(data)
        curr = get_node_at(index-1)

        new_node.next = curr.next
        curr.next = new_node
        @length += 1
      end
    end

    def get_node_at(index)
      return @last.next if index == 0
      return @last if index == @length

      curr = @last.next
      index.times do 
        curr = curr.next
      end

      return curr
    end

    # removes a node at 'index' from the list  
    def remove_at(index)
      data = nil
      if index < 0 or index > @length
        puts "... cannot remove a node at index #{index}"
        return
      elsif @length == 1
        # remove the only node
        data = @last.data
        @last = nil
      elsif index == 0
        # remove the head node
        data = @last.next.data
        @last.next = @last.next.next
      elsif index == @length
        # remove the last node
        data = @last.data
        curr = get_node_at(index-1)
        curr.next = @last.next
        @last = curr
      else
        # remove a node in between nodes
        curr = get_node_at(index-1)
        data = curr.next.data
        curr.next = curr.next.next
      end

      @length -= 1
      return data
    end

    # search for 'data' and return its index or -1 
    def search(data)
      return 0 if @last.next.data == data
      return @length if @last.data == data

      curr = @last.next.next
      for i in 1...@length do
        return i if curr.data == data
        curr = curr.next
      end

      return -1
    end

    def empty?
      return @length == 0
    end

    def print_list(n=@length)
      if @length != 0 
        curr = @last.next
        1.upto n do |i|
          print "#{curr.data} "
          curr = curr.next
          puts if (i % @length) == 0
        end
        puts
      else
        puts "list is empty.."
      end
    end
  end

  class Doubly
    class Node
      attr_accessor :data, :prev, :next

      def initialize(data, prev=nil, _next=nil)
        @data = data
        @prev = prev
        @next = _next
      end
    end

    def initialize
      @head = nil
      @length = 0
    end

    # inserts a node at the end
    def insert(data)
      if @head == nil
        @head = Node.new(data)
        @head.prev = @head
        @head.next = @head
      else
        new_node = Node.new(data, @head.prev, @head)
        @head.prev.next = @head.prev = new_node
      end
      @length += 1
    end

    def insert_at(index, data)
      if index < 0 or index > @length
        # out of bounds
        puts ".. cannot insert '#{data}' at index #{index}"
      elsif @length == 0 or index == @length
        insert(data)
      elsif index == 0
        new_node = Node.new(data, @head.prev, @head)
        @head.prev.next = new_node
        @head.prev = new_node
        @head = new_node

        @length += 1
      else
        curr = get_node_at(index-1)
        new_node = Node.new(data, curr, curr.next)
        curr.next = new_node
        curr.next.prev = new_node

        @length += 1
      end

    end

    def get_node_at(index)
      curr = @head
      index.times do
        curr = curr.next
      end

      curr
    end

    def remove_at(index)
      data = nil

      if index < 0 or index >= @length
        puts "... cannot remove a node at index #{index}"
        return
      elsif @length == 1
        data = @head.data
        @head = nil
        @length = 0
      elsif index == 0
        data = @head.data
        @head.next.prev = @head.prev
        @head.prev.next = @head.next
        @head = @head.next
      elsif index == @length-1
        data = @head.prev.data

        @head.prev.prev.next = @head
        @head.prev = @head.prev.prev
      else
        curr = get_node_at(index)
        curr.prev.next = curr.next
        curr.next.prev = curr.prev
      end

      @length -= 1

      puts "index(#{index})  len(#{@length})"

      data
    end

    def search(data)
      return 0 if @head.data == data
      return @length if @head.prev.data == data

      curr = @head.next
      for i in 1...@length
        return i if curr.data == data
        curr = curr.next
      end
      
      return -1
    end

    def empty?
      return @length == 0
    end

    def print_list(n=@length)
      if @length != 0 
        curr = @head
        1.upto n do |i|
          print "#{curr.data} "
          curr = curr.next
          puts if (i % @length) == 0
        end
        puts
      else
        puts "list is empty.."
      end
    end

    def len
      @length
    end
  end
end

#list = CircularLinkedList::Singly.new
list = CircularLinkedList::Doubly.new
puts "insert 10 at 0"
list.insert_at(0, 10)
list.print_list
puts "insert 15 at 1"
list.insert_at(1, 15)
list.print_list
puts "isert 12 at 1"
list.insert_at(1, 12)
list.print_list
puts "insert 70"
list.insert(70)
list.print_list

puts "removing at 0 (len: #{list.len})"
list.remove_at(0)
list.print_list

puts "removing at 1 (len: #{list.len})"
list.remove_at(1)
list.print_list(5)
