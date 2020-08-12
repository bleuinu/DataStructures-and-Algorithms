n = gets.to_i
count = [0] * 10001;
n.times do
  count[gets.to_i] += 1
end

1.upto(10000) do |i|
  if count[i] > 0
    puts "#{i}\n" * count[i]
  end
end
  
