class MyCircularQueue
  def initialize(k)
    @queue = Array.new(k, 0)
    @capacity = k
    @count = 0
    @head = -1
    @tail = -1
  end

  def en_queue(value)
    return false if is_full
    if is_empty
      @head = 0
      @tail = 0
      @queue[@tail] = value 
    else
      @tail += 1
      @tail = @tail % @capacity if @tail >= @capacity
      @queue[@tail] = value
    end

    @count += 1
    return true
  end

  def de_queue()
    if is_empty
      @head = -1
      @tail = -1
      return false
    end
    @queue[@head] = nil
    @count -= 1
    @head+= 1
    @head = @head % @capacity if @head >= @capacity
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
    @count == 0
  end

  def is_full()
    @count == @capacity
  end
end
