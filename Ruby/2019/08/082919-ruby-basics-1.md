## August 29, 2019

### Ruby
#### Basics
- Ruby는 모든 것이 개체다.

- 문자열의 경우 C/C++에서는 연속된 문자를 의미하지만 루비에서는 연속된 바이트를 의미한다.

- `!`가 붙어있는 메소드는 본래의 데이터의 영향을 끼친다.
	```ruby
	str = "Hello";
	str.upcase		# => "HELLO"
	puts str			# => "Hello"

	str.upcase!		# => "HELLO"
	put str				# => "HELLO"
	```

- _predicates_ (불리언 값을 반환하는 메소드)들에는 물음표가 붙는다.
	```ruby
	str = ''
	str.empty?	# => true

	str = "Hello"
	str.empty?	# => talse
	```

#### String
- 'Here Document'
	``` ruby
	long_string = <<EOF
	Hello, World!
	Hello, Ruby!
	This is my long string!.
	EOF
	```	
	위에서 EOF는 키워드가 아니다.  
	시작과 끝을 의미하는 단어로써 원하는 단어, 가령 END 라든가, 를 사용할 수 있다.

- << 
	문자열을 합칠 때 사용한다.
	```ruby
	str = ''
	str << "hello"
	puts str				# => "hello"
	```

	아래와 같은 경우 약간의 비효율적인 면이 있다.
	```ruby
	str = ""
