class Stack
    def initialize(size)
        @SIZE = size
        @item = 0
        @arr = Array.new(@SIZE)
    end

    def push(data)
        if self.full?
            puts "stack is full..."
            return
        end

        @arr[@item] = data
        @item += 1
    end

    def pop
        if self.empty?
            puts "stack is empty..."
            return
        end

        @item -= 1
        data = @arr[@item]
    end

    def peek
        if self.empty? 
            puts "stack is empty..."
            return
        end
        @arr[@item-1]
    end

    def empty?
        @item == 0
    end

    def full?
        @item == @SIZE
    end
end