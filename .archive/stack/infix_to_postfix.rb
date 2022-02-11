class String 
  def is_operand?
    !!match(/^[a-zA-Z]$/)
  end

  def precedence
    return 5 if self == '^'
    return 2 if self == '*' or self == '\/'
    return 1 if self == '+' or self == '-'
    return 0
  end

  def to_postfix
    expr = self
    size = expr.size
    op = []
    str = ''

    # 1. Scan the infix expression from left to right. 
    for i in 0...size do 
      # 4. If the scanned character is an ‘(‘, push it to the stack. 
      if expr[i] == '('
        op.push(expr[i])
        # 5. If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
      elsif expr[i] == ')'
        while op.last != '('
          str += op.pop
        end
        op.pop
        # 2. If the scanned character is an operand, output it. 
      elsif expr[i].is_operand?
        str += expr[i]
      else  # 3. Else
        if op.empty? or expr[i].precedence > op.last.precedence
          #   1 If the precedence of the scanned operator is greater than the 
          #     precedence of the operator in the stack
          #     (or the stack is empty or the stack contains a ‘(‘ ), push it. 
          op.push(expr[i])
        else
          #   2 Else, Pop all the operators from the stack which are 
          #     greater than or equal to in precedence than that of the scanned operator. 
          #     After doing that Push the scanned operator to the stack. 
          #     (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
          while !op.empty? and expr[i] != '(' and expr[i].precedence <= op.last.precedence
            str += op.pop
          end
          op.push(expr[i])
        end
      end
    end

    while !op.empty?
      str += op.pop
    end

    return str
  end
end

while true
  print "Enter an expression: "
  expr = gets.chomp 
  break if expr.empty?
  puts "postfix: #{expr.to_postfix}"
end
