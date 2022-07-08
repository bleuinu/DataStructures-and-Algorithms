class Node 
    attr_accessor :next
    attr_reader   :data

    def initialize(data)
        @data = data
        @next = nil
    end 
end 

class Stack 
    def initialize 
        @head = nil
    end 

    def push(data)
        if @head == nil
            @head = Node.new(data)
        else
            temp = Node.new(data)
            temp.next = @head
            @head = temp
        end
    end 

    def pop 
        if self.empty?
            puts "stack is empty..."
            return
        else
            data = @head.data
            temp = @head
            @head = @head.next
            temp = nil
            return data
        end
    end 

    def peek 
        if self.empty?
            puts "stack is empty..."
        else 
            return @head.data
        end 
    end 

    def empty?
        @head == nil
    end 

    def to_s
        if self.empty?
            puts "stack is empty..."
            return
        end 

        temp = @head

        str = ""
        while temp != nil 
            str = "%d " % temp.data + str
            temp = temp.next
        end 
        puts str
    end
end 