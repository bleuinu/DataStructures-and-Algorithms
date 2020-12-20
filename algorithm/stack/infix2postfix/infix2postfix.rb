def priority(c)
  return 2 if (c=='*' or c=='/')
  return 1 if (c=='+' or c=='-')
  return 0
end

def to_postfix(expr)
  op = []
  size = expr.size
  size.times do |i|
    if (expr[i]>='A' and expr[i]<='Z') 
      print expr[i]
    elsif (expr[i]=='(')
      op << expr[i]
    elsif (expr[i]=='+' or expr[i]=='-' or 
           expr[i]=='*' or expr[i]=='/')
      if (op.size==0 || op.last=='(' || (priority(expr[i]) > priority(op.last)))
        op << expr[i] 
      else 
        while priority(expr[i]) <= priority(op.last)
          print op.last 
          op.pop 
        end
        op << expr[i]
      end
    elsif (expr[i]==')')
      while op.last != '('
        print op.last 
        op.pop
      end
      op.pop
    end
  end

  op.size.times do
    print op.pop
  end
  puts
end

expr = gets.chomp
to_postfix(expr)
