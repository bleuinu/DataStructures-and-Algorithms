def manacher s
	# manacher only works with odd, 
    # so add (n+1) special characters (#) in between every character
    str = s.gsub(/(.{1})/, '#\1') + '#'

    len = 2 * s.size + 1
    p = [0] * len        # => expansion length
    c = 0				 # => center of the longest palindrome substring
    r = 0				 # => right most boundary
    maxLen = 0           

    for i in (0...len) do
        mirror = 2 * c - i;

        if i < r
            p[i] = [r - i, p[mirror]].min
        end

        a = i + (1 + p[i])
        b = i - (1 + p[i])
        while a < len && b >= 0 && str[a] == str[b]
            p[i] += 1
            a += 1
            b -= 1
        end
        
        if (i + p[i] > r)
            c = i
            r = i + p[i]

            if p[i] > maxLen
                maxLen = p[i]
            end
        end       
    end

    maxLen
end

str = gets.chomp
puts manacher(str)
