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

    def initialize
    # constructor
      @last = nil
      @length = 0
    end

    def insert(data)
    # inserts a node at the end
      if @last == nil
        @last = Node.new(data)
        @last.next = @last
      else
        @last.next = @last = Node.new(data, @last.next)
      end

      @length += 1
    end

    def insert_at(index, data)
    # inserts a node at 'index'
      if index < 0 or index > @length
        puts ".. cannot insert '#{data}' at index #{index}"
      elsif @length == 0 or index == @length
      # insert at the back
        insert(data)
      elsif index == 0
      # insert at the front
        new_node = Node.new(data, @last.next)
        @last.next = new_node
        
        @length += 1
      else
      # insert in between
        curr = get_node_at(index-1)
        new_node = Node.new(data, curr.next)
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

    def remove_front
      data = @last.next.data
      @last.next = @last.next.next

      @length -= 1
      data
    end

    def remove_last
      data = @last.data

      curr = get_node_at(@length-2)
      curr.next = @last.next
      @last = curr

      @length -= 1
      data
    end

    def remove_at(index)
    # removes a node at 'index' from the list  
      data = nil
      if index < 0 or index > @length
        puts "... cannot remove a node at index #{index}"
        return
      elsif @length == 1
      # remove the only node
        data = @last.data
        @last = nil
        @length = 0
      elsif index == 0
      # remove the head node
        data = remove_front
      elsif index == @length-1
      # remove the last node
        data = remove_last
      else
      # removes a node in between nodes
        curr = get_node_at(index-1)
        data = curr.next.data
        curr.next = curr.next.next

        @length -= 1
      end

      return data
    end

    def search(data)
    # search for 'data' and return its index or -1 
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

    def print_list
      if @last != nil
        curr = @last.next
        while curr != @last do
          print "#{curr.data} "
          curr = curr.next
        end
        puts curr.data
      else
        puts "list is empty.."
      end
    end

    def length
      @length
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

    def insert(data)
    # inserts a node at the end
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
    # inserts a node at 'index'
      if index < 0 or index > @length
        puts ".. cannot insert '#{data}' at index #{index}"
      elsif @length == 0 or index == @length
      # insert at the back
        insert(data)
      elsif index == 0
      # insert at the front
        new_node = Node.new(data, @head.prev, @head)
        @head.prev.next = new_node
        @head.prev = new_node
        @head = new_node

        @length += 1
      else
      # insert in between nodes
        curr = get_node_at(index)
        new_node = Node.new(data, curr.prev, curr)
        curr.prev.next = curr.prev = new_node

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

    def remove_front
      data = @head.data

      @head.next.prev = @head.prev
      @head.prev.next = @head.next
      @head = @head.next

      @length -= 1
      data
    end

    def remove_last
      data = @head.prev.data
        
      @head.prev.prev.next = @head
      @head.prev = @head.prev.prev

      @length -= 1
      data
    end

    def remove_at(index)
    # removes a node at 'index'
      data = nil

      if index < 0 or index >= @length
        puts "... cannot remove a node at index #{index}"
        return
      elsif @length == 1
        data = @head.data
        @head = nil
        @length = 0
      elsif index == 0
      # removes the first node
        data = remove_front
      elsif index == @length-1
      # removes the last node
        data = remove_last
      else
      # removes a node in between nodes
        curr = get_node_at(index)
        curr.prev.next = curr.next
        curr.next.prev = curr.prev

        @length -= 1
      end

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

    def print_list
      if @head != nil 
        print "#{@head.data} "
        curr = @head.next
        while curr != @head
          print "#{curr.data} "
          curr = curr.next
        end
        puts " ( len: #{@length} )"
      else
        puts "list is empty.."
      end
    end

    def length
      @length
    end
  end
end
