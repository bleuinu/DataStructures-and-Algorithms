class MyCircularQueue
  def initialize(k)
    @queue = Array.new(k, 0)
    @capacity = k
    @head = -1
    @tail = -1
  end

  def en_queue(value)
    return false if is_full
    @head = 0 if is_empty
    @tail = (@tail+1) % @capacity
    @queue[@tail] = value

    return true
  end

  def de_queue()
    return false if is_empty
    if @head == @tail
      @head = -1
      @tail = -1
      return true
    end
    @head = (@head + 1) % @capacity
    return true
  end

  def front()
    return -1 if is_empty
    @queue[@head]
  end

  def rear()
    return -1 if is_empty
    @queue[@tail]
  end

  def is_empty()
    @head == -1
  end

  def is_full()
    ((@tail + 1) % @capacity) == @head
  end
end
