# Skip list implementation
class Node 
  attr_accessor :key, :forward
  def initialize(key, level)
    @key = key
    # list to hold refs to node of diffirent level
    @forward = [nil]*(level+1)
  end
end

class SkipList
  def initialize(max_level, p)
    # Maximum level for this skip list
    @MAX_LEVEL = max_level

    # p => fraction of the nodes with level
    # i => also have level+1 refs
    @p = p

    # create a header node and initialize key to -1
    @header = Node.new(-1, @MAX_LEVEL)

    # current level of skip list
    @level = 0
  end

  def random_level()
    level = 0
    while  rand < @p and level < @MAX_LEVEL
      level += 1
    end

    level
  end

  def insert_element(key)
    update = [nil]*(@MAX_LEVEL+1)
    curr = @header

    i = @level
    while i >= 0
      while (curr.forward[i]) and (curr.forward[i].key < key)
        curr = curr.forward[i]
      end
      update[i] = curr
      i-= 1
    end

    curr = curr.forward[0]

    if curr == nil or curr.key != key
      rlevel = random_level()

      if rlevel > @level
        for i in (@level+1)...(rlevel+1)
          update[i] = @header
        end
        @level = rlevel
      end

      n = Node.new(key, rlevel)

      for i in 0..rlevel
        n.forward[i] = update[i].forward[i]
        update[i].forward[i] = n
      end
      puts "successfully inserted key #{key}"
    end
  end

  def delete(search_key)
    update = [nil]*(@MAX_LEVEL+1)
    curr = @header

    i = @level
    while i >= 0
      while (curr.forward[i]) and (curr.forward[i].key < search_key)
        curr = curr.forward[i]
      end
      update[i] = curr
      i -= 1
    end

    curr = curr.forward[0]

    if curr != nil and curr.key == search_key
      for i in 0..@level
        break if update[i].forward[i] != curr
        update[i].forward[i] = curr.forward[i]
      end
    end

    while @level>0 and @header.forward[@level]==nil
      @level -= 1
    end

    puts "Successfully deleted #{search_key}"
  end

  def search(key)
    curr = @header

    i = @level
    while i >= 0
      while curr.forward[i] and curr.forward[i].key < key
        curr = curr.forward[i]
      end

      i-=1
    end

    curr = curr.forward[0]

    if curr and curr.key == key
      puts "Found key #{key}"
    else 
      puts "key #{key} not found"
    end
  end

  def print_list()
    puts "********Skip List********"
    for i in 0..@level
      node = @header.forward[i]
      puts "Level #{i}: "
      while node != nil
        print "#{node.key} "
        node = node.forward[i]
      end
      puts
    end
  end
end


list = SkipList.new(3, 0.5)

list.insert_element(3)
list.insert_element(6)
list.insert_element(7)
list.insert_element(9)
list.insert_element(12)
list.insert_element(19)
list.insert_element(17)
list.insert_element(26)
list.insert_element(21)
list.insert_element(25)
list.print_list

list.search(9)
list.search(1)
list.search(21)

list.delete(21)
list.print_list

list.delete(3)
list.delete(6)
list.print_list
