# Ruby Basics 2

## 상수
루비에서 상수는 대문자로 나타낸다.

```ruby
NAME = "Jii Yoo"
ADDRESS = "1234 Ruby st."
```

상수란 변하지 않는 값을 의미하는데 루비에서는 상수의 값을 바꾸는게 가능하다.

```ruby
NAME = "Jii"
puts NAME      # => "Jii"

NAME = "Myoi"
puts NAME      # => "Myoi"
```

하지만 상수의 값을 바꾸려고 할 때, 경고 메세지가 출력된다.

```
(test.rb):2 warning: already initialized constant TEST
(test.rb):1 warning: previous definition of TEST was here
```

상수는 상수로만 사용하자.

## File I/O
- `w`: write
- `r`: read
- `a`: append
- `[w/r/a]+`: both write and read

### 파일에 쓰기
```ruby
coffees = %w{Americano Mocha Black}

open('coffee.txt', "w") do |file|
	coffees.each { |coffee| file.puts coffee }
end

# coffee.txt
# -----------
# Americano
# Mocha
# Black
```

### 파일에서 읽기 
```ruby
coffees = []

open('coffee.txt', "r") do |file|
	file.each { |coffee| coffees << coffee }
end

puts coffee

# output
#---------
# Americano
# Mocha
# Black
```
