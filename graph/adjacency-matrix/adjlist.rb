class Node 
  attr_accessor :data, :next 

  def initialize(data) 
    @data = data 
    @next = nil 
  end
end 

class AdjList
  def initialize(v)
    @graph = []
    @v = v
  end

  def add_edge(src, dest)
    if @graph[src] 
      @graph[src].append(dest) 
    elsif @graph[src] == nil 
      @graph[src] = [dest]
    end
    if @graph[dest]
      @graph[dest].append(src)
    elsif @graph[dest] == nil
      @graph[dest] = [src]
    end
  end

  def display 
    for i in 0...@v 
      puts "Adjacency list of vertex #{i}"
      print "head"
      temp = @graph[i] 
      temp.each do |data|
        print " -> #{data}"
      end
      puts
    end
  end

end

v = 5
graph = AdjList.new(v)
graph.add_edge(0, 1)
graph.add_edge(0, 4)
graph.add_edge(1, 2)
graph.add_edge(1, 3)
graph.add_edge(1, 4)
graph.add_edge(2, 3)
graph.add_edge(3, 4)

graph.display
