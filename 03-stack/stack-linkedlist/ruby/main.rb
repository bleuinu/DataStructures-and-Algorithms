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
        @top = nil
    end 

    def push(data)
        if self.empty?
            @top = Node.new(data)
        else
            temp = Node.new(data)
            temp.next = @top
            @top = temp
        end
    end 

    def pop 
        if self.empty?
            puts "stack is empty..."
            return
        else
            data = @top.data
            temp = @top
            @top = @top.next
            temp = nil
            return data
        end
    end 

    def peek 
        if self.empty?
            puts "stack is empty..."
        else 
            return @top.data
        end 
    end 

    def empty?
        @top == nil
    end 

    def to_s
        if self.empty?
            puts "stack is empty..."
            return
        end 

        temp = @top

        str = ""
        while temp != nil 
            str = "%d " % temp.data + str
            temp = temp.next
        end 
        puts str
    end
end 