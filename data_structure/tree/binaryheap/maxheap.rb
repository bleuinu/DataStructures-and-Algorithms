class Integer 
  N_BYTES = [42].pack('i').size 
  N_BITS = N_BYTES * 16
  MAX = 2 ** (N_BITS - 2) - 1 
  MIN = -MAX - 1
end

class MaxHeap
  def initialize(cap)
    @harr = [0] * cap
    @heap_size = 0
    @capacity = 10
  end
  
  def max_heapify(index)
    l = left(index) 
    r = right(index)
    largest = index 

    if l < @heap_size and @harr[l] > @harr[index] 
      largest = l 
    end
    if r < @heap_size and @harr[r] > @harr[largest] 
      largest = r
    end
    if largest != index 
      @harr[index], @harr[largest] = @harr[largest], @harr[index] 
      max_heapify(largest)
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

  def getMax 
    return @harr[0]
  end

  def extract_max
    return Integer::MIN if @heap_size <= 0 
    if @heap_size == 1 
      @heap_size -= 1 
      return harr[0]
    end

    root = @harr[0] 
    @harr[0] = @harr[@heap_size - 1]
    @heap_size -= 1 
    max_heapify(0)

    return root
  end

  def increase_key(index, new_val) 
    @harr[index] = new_val 
    while index != 0 and @harr[index] > @harr[parent(index)]
      @harr[index], @harr[parent(index)] = @harr[parent(index)], @harr[index]
      index = parent(index)
    end
  end 

  def delete_key(index) 
    increase_key(index, Integer::MAX) 
    extract_max();
  end 

  def insert_key(k)
    if @heap_size == @capacity 
      puts "Overflow: could not insert a key" 
      return 
    end

    index = @heap_size 
    @heap_size += 1 
    @harr[index] = k 

    while index != 0 and @harr[index] > @harr[parent(index)]
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

h = MaxHeap.new(10) 
h.insert_key(1)
h.insert_key(5)
h.insert_key(2)
h.insert_key(7)
h.insert_key(3)
h.insert_key(8)
h.insert_key(4)
h.insert_key(9)
h.insert_key(6)
h.print_heap

h.extract_max
h.print_heap

h.delete_key(5) 
h.print_heap
