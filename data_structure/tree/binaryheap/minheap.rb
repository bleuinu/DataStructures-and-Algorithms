class Integer 
  N_BYTES = [42].pack('i').size 
  N_BITS = N_BYTES * 16
  MAX = 2 ** (N_BITS - 2) - 1 
  MIN = -MAX - 1
end

class MinHeap
  def initialize(cap)
    @harr = [0] * cap
    @heap_size = 0
    @capacity = 10
  end
  
  def min_heapify(index)
    l = left(index) 
    r = right(index)
    smallest = index 

    if l < @heap_size and @harr[l] < @harr[index] 
      smallest = l 
    end
    if r < @heap_size and @harr[r] < @harr[smallest] 
      smallest = r
    end
    if smallest != index 
      @harr[index], @harr[smallest] = @harr[smallest], @harr[index] 
      min_heapify(smallest)
    end
  end 

  def parent(index)
    return (index-1) / 2
  end 

  def left(index) 
    return (2*index) + 1
  end 

  def right(index)
    return (2*index) + 2
  end

  def get_min 
    return @harr[0]
  end

  def extract_min
    return Integer::MAX if @heap_size <= 0 
    if @heap_size == 1 
      @heap_size -= 1 
      return harr[0]
    end

    root = @harr[0] 
    @harr[0] = @harr[@heap_size - 1]
    @heap_size -= 1 
    min_heapify(0)

    return root
  end

  def decrease_key(index, new_val) 
    @harr[index] = new_val 
    while index != 0 and @harr[index] < @harr[parent(index)]
      @harr[index], @harr[parent(index)] = @harr[parent(index)], @harr[index]
      index = parent(index)
    end
  end 

  def delete_key(index) 
    decrease_key(index, Integer::MIN) 
    extract_min();
  end 

  def insert_key(k)
    if @heap_size == @capacity 
      puts "Overflow: could not insert a key" 
      return 
    end

    index = @heap_size 
    @heap_size += 1 
    @harr[index] = k 

    while index != 0 and @harr[index] < @harr[parent(index)]
      @harr[index], @harr[parent(index)] = @harr[parent(index)], @harr[index]
      index = parent(index)
    end
  end 

  def print_heap 
    0.upto(@heap_size - 1) do |i| 
      print "#{@harr[i]} "
    end
    puts
  end
end

h = MinHeap.new(10) 
h.insert_key(10)
h.insert_key(15)
h.insert_key(30)
h.insert_key(40)
h.insert_key(50)
h.insert_key(100)
h.insert_key(40)
h.print_heap

puts h.extract_min
h.print_heap

h.decrease_key(3, 2)
h.print_heap
