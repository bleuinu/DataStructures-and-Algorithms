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

        @rear = (@rear + 1) % @SIZE;
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
        puts "front:#{@arr[@front]}   rear:#{@arr[@rear]}"

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
        (@front == 0 and @rear == @SIZE-1) or (@front == @rear + 1)
    end

    def to_s
        head = @front
        str = ""
        while head != @rear 
            str += "#{@arr[head]} "
            head += 1

            if head == @SIZE
                head = 0
            end
        end 

        str += "#{@arr[head]}"
    end
end