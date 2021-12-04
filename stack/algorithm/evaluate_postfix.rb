# Reverse Polish Notation = Postfix
class String
  def is_num
    !!match(/^([-]?)[0-9]+$/)
  end
end

def eval_rpn(tokens)
  op = []
  tokens.each do |t|
    if t.is_num
      op.push(t.to_i)
    else
      a = op.pop
      b = op.pop
      if t == "+"
        op.push(a+b)
      elsif t == "-"
        op.push(b-a)
      elsif t == "*"
        op.push(a*b)
      elsif t == "/"
        op.push((b/a.to_f).to_i)
      end
    end
  end
  op.pop
end

puts eval_rpn(["2","1","+","3","*"]) # output = 9
puts eval_rpn(["4","13","5","/","+"]) # output = 6
puts eval_rpn(["10","6","9","3","+","-11","*","/","*","17","+","5","+"]) # output = 22
