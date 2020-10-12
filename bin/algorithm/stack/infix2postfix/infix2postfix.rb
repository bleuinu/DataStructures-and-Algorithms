## used to calculate priority of each operators
def priority(c)
  return 2 if (c=='*' or c=='/')
  return 1 if (c=='+' or c=='-')
  return 0
end

def to_postfix(expr)
  op = []
  size = expr.size
  size.times do |i|
    ## print any operands (numbers)
    if (expr[i]>='A' and expr[i]<='Z') 
      print expr[i]
    ## push '(' right away
    elsif (expr[i]=='(')
      op << expr[i]
    ## if it's an operator, push it to the stack if 
    elsif (expr[i]=='+' or expr[i]=='-' or expr[i]=='*' or expr[i]=='/')
      # 1. stack is empty
      # 2. top of the stack is '('
      # 3. scanned operator (expr[i]) is > an operator on top of the stack (op.last)
      if (op.size==0 || op.last=='(' || (priority(expr[i]) > priority(op.last)))
        op << expr[i] 
      ## Else pop operators on the stack until above condition is met
      else 
        while priority(expr[i]) <= priority(op.last)
          print op.last 
          op.pop 
        end
        op << expr[i]
      end
    ## if it's a ')', pop until '(' operator
    elsif (expr[i]==')')
      while op.last != '('
        print op.last 
        op.pop
      end
      op.pop
    end
  end

  ## pop any left over operators on the stack
  op.size.times do
    print op.pop
  end
  puts
end

expr = gets.chomp
to_postfix(expr)
