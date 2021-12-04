class MinStack
  def initialize()
    @stack = []
    @min = []
  end

  def push(val)
    @stack.push(val)
    @min.push(val) if @min.empty? or val <= @min[-1]
  end

  def pop()
    @min.pop if @stack[-1] == @min[-1]
    @stack.pop
  end

  def top()
    @stack[-1]
  end

  # this should be O(1)
  def get_min()
    @min[-1]
  end
end
