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

        if @tail == @SIZE
            @tail = 0
        end
    end 

    def dequeue
        if self.empty?
            puts "Queue is empty..."
            return
        end

        item = @arr[@head]
        if @head == @tail 
            puts "Queue is empty..."
            @head = -1
            @tail = -1
            return
        else
            @head += 1
        end 
        item
    end 

    def front
        if !self.empty?
            @arr[@head]
        end
    end

    def empty?
        @head == -1 && @tail == -1
    end

    def full?
        (@head == 0 and @tail == @SIZE-1) or (@head == @tail + 1)
    end

    def to_s
        head = @head
        str = ""
        while head != @tail 
            str += "#{@arr[head]} "
            head += 1

            if head == @SIZE 
                head = 0
            end
        end 

        str
    end
end

q = Queue.new(8)
puts "empty? #{q.empty?}"
puts "full? #{q.full?}"
puts 

5.times do
    q.enqueue(1)
    puts q.to_s
end

puts
puts "empty? #{q.empty?}"
puts "full? #{q.full?}"
puts

3.times do
    q.dequeue
    puts q.to_s
end

puts

6.times do 
    q.enqueue(rand(1..50))
    puts q.to_s
end

puts "front: #{q.front}"