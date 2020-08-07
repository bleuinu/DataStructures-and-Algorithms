def getSA(s)
    str = s
    $SA = (0..s.size-1).sort_by{ |i| str[i..-1]}
end

s = gets.chomp
$SA = nil
getSA(s)
$SA.each do |i|
    puts s[i..-1]
end