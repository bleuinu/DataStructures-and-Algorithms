class Queue
    def initialize(size)
        @SIZE = size
        @front = -1
        @rear = -1
        @arr = [nil] * @SIZE
    end 

    def enqueue(item)
        if self.full?
            puts "Queue is full.."
            return
        elsif self.empty?
            @front = 0
        end

        @rear += 1
        @arr[@rear] = item
    end 

    def dequeue
        if self.empty?
            puts "Queue is empty..."
            return
        end

        item = @arr[@front]
        if @front == @rear
            @front = -1
            @rear = -1
        else
            @front += 1
        end
        
        item
    end 

    def front
        if !self.empty?
            @arr[@front]
        end
    end

    def empty?
        (@front == -1 && @rear == -1)
    end

    def full?
        @rear == @SIZE-1
    end

    def to_s
        head = @front
        str = ""
        while head != @rear 
            str += "#{@arr[head]} "
            head += 1
        end 
        
        str += "#{@arr[head]} "
    end
end


q = Queue.new(5)
q.enqueue(1)
puts q.to_s
q.enqueue(2)
puts q.to_s
q.enqueue(3)
puts q.to_s
q.enqueue(4)
puts q.to_s
q.enqueue(5)
puts q.to_s

q.dequeue
puts q.to_s
q.dequeue
puts q.to_s
q.dequeue
puts q.to_s

q.enqueue(10)
puts q.to_s
q.enqueue(11)
puts q.to_s
q.enqueue(12)
puts q.to_s

q.dequeue
puts q.to_s
q.enqueue(17)
puts q.to_s
