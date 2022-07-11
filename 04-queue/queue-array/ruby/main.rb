class Queue
    def initialize(size)
        @SIZE = size
        @head = -1
        @tail = -1
        @arr = [nil] * @SIZE
    end 

    def enqueue(item)
        if self.full?
            puts "Queue is full.."
            return
        elsif self.empty?
            @head = 0
            @tail = 0
        end

        @arr[@tail] = item
        @tail += 1
    end 

    def dequeue
        if self.empty?
            puts "Queue is empty..."
            @head = -1
            @tail = -1
            return
        end

        item = @arr[@head]
        @head += 1
        item
    end 

    def front
        if !self.empty?
            @arr[@head]
        end
    end

    def empty?
        (@head == -1 && @tail == -1) or (@head == @tail)
    end

    def full?
        @tail == @SIZE-1
    end

    def to_s
        head = @head
        str = ""
        while head != @tail 
            str += "#{@arr[head]} "
            head += 1
        end 

        str
    end
end