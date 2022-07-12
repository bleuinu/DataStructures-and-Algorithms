class Node 
    attr_accessor :next
    attr_reader :data

    def initialize(data) 
        @data = data
        @next = nil
    end
end

class Deque
    def initialize
        @front = nil
        @rear = nil
    end

    def addFront(data) 
        if self.empty?
            @front = Node.new(data)
            @rear = @front
        else 
            node = Node.new(data)
            node.next = @front
            @front = node
        end
    end
    
    def addRear(data)
        if self.empty?
            @front = Node.new(data)
            @rear = @front
        else 
            @rear.next = Node.new(data)
            @rear = @rear.next
        end
    end
    
    def removeFront
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

    def removeRear
        if self.empty?
            puts "Queue is empty..."
            return
        end

        temp = @front
        while temp.next != @rear
            temp = temp.next
        end

        item = temp.data
        temp.next = nil
        @rear = temp
        item
    end

    def front
        if !self.empty?
            @front.data
        end
    end

    def rear
        if !self.empty?
            @rear.data
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