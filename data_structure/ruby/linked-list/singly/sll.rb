class Node
  attr_accessor :data, :next
  
  def initialize(data)
    @data = data
    @next = nil
  end
end

class SinglyLinkedList
  attr_reader :head, :length

  def initialize()
    @head = nil
    @length = 0
  end

  def add(value)
    new_node = Node.new(value)
    if @head == nil
      @head = new_node
    else
      curr = @head
      while curr.next != nil
        curr = curr.next
      end

      curr.next = new_node
    end
    @length += 1
  end

  # first node => position 1
  def remove(pos)
    return -1 if pos < 1 or pos > @length
    if pos==1
      @head = @head.next
    else
      curr = @head
      for i in 1...(pos-1)
        curr = curr.next
      end

      curr.next = curr.next.next
    end

    @length -= 1
  end

  # first node => position 1
  def search_node_at(pos)
    if @head == nil
      puts "---- list is empty"
      return 
    elsif pos < 1 or pos > @length
      puts "---- invalid position"
      return
    else
      curr = @head
      for i in 1...pos
        curr = curr.next
      end
      return curr
    end
  end

  def length()
    @length
  end

  def print_list()
    curr = @head
    for i in 0...@length
      print "#{curr.data} "
      curr = curr.next
    end
    puts
  end
end

root = SinglyLinkedList.new()
1.upto(5) do |x|
  root.add(x)
end
puts "len: #{root.length}"
root.print_list

root.remove(gets.to_i)
puts "len: #{root.length}"
root.print_list

puts "search_node_at(2): #{root.search_node_at(2).data}"
