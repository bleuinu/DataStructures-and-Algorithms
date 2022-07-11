class Node 
    attr_accessor :next
    attr_reader :data

    def initialize(data) 
        @data = data
        @next = nil
    end
end

class Queue
    def initialize
        @front = nil
        @rear = nil
    end

    def enqueue(data)
        if self.empty?
            @front = Node.new(data)
            @rear = @front
        else 
            @rear.next = Node.new(data)
            @rear = @rear.next
        end
    end

    def dequeue
        if self.empty?
            puts "Queue is empty..."
            return
        end

        item = @front.data
        temp = @front
        @front = @front.next
        temp.next = nil
        item
    end

    def front
        if !self.empty?
            @front.data
        end
    end

    def empty?
        @front == nil
    end

    def to_s
        temp = @front

        str = []
        while temp != nil do
            str.push(temp.data)
            temp = temp.next
        end 
        str.join(' ')
    end
end