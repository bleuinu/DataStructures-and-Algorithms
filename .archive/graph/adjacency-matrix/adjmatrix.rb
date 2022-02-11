class AdjMatrix
  def initialize(v)
    @graph = Array.new(v) { Array.new(v) }
    @v = v
  end

  def set_edge(frm, to, cost = nil)
    @graph[frm][to] = cost
    @graph[to][frm] = cost
  end

  def display 
    for i in 0...@v
      print "#{i}: "
      for j in 0...@v
        if @graph[i][j]
          print "(#{j}, #{@graph[i][j]}) -> "
        end
      end
      puts
    end
  end
  
end

graph = AdjMatrix.new(10)
graph.set_edge(0,5,10)
graph.set_edge(0,2,20)
graph.set_edge(2,1,30)
graph.set_edge(1,5,40)
graph.set_edge(5,4,50)
graph.set_edge(6,4,60)

graph.display
