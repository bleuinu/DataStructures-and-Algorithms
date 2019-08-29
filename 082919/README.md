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
	fname = "Jii"
	lname ="Yoo"

	str << "My name is" << '${fname} ${lname}'		# => "My name is Jii Yoo"
	```
	이유는 일시적으로 이름과 성을 담을 문자열을 만든 후에 합치기 때문이다. 그렇기 때문에
	아래처럼 해야 가장 효율적이게 된다.
	```ruby
	str << "My name is" << fname} << ' ' << lname
	```

- Array#join
	Array#join의 경우 separator를 지정해줘야 되는데 이 구분자가 마지막 요소 이후에는 영향을 끼치지 않는다. 
	```ruby
	data = ['ko', 'en', 'ja']
	data.join(' and ')					# => "ko and en and ja"
	```
	당연한게 아닌가? 하는 생각이 들지만 타 언어로 위와 비슷하게 구현을 할 경우 
	아래와 같은 상황이 발생했던 적이 있어서 유용하다고 생각한다.
	```ruby
	str = ''
	data = ['ko', 'en', 'ja']

	data.each { |s| str << s << " and " }	# => "ko and en and ja and "
	```

- Substitution
	* printf-style
		```ruby
		template = "Hello my name is %s."
		template % "Jii"			# => "Hello my name is Jii.
		template % "Myoi"			# => "Hello my name is Myoi.
		```
	* ERB templates
		``` ruby
		# in irb
		require 'erb'

		template = ERB.new %q{Hello my name is <%= name %>.}

		# if not in irb, 'puts template.result'
		name = "Myoi"
		template.result(binding)	# => "Hello my name is Myoi."
		name = "Jii"
		template.result(binding)	# => "Hello my name is Jii."
		```
- Regular Expression
  * /\w+/
	  + problem: can't determine words with puctuations (`fo'c'sle` or `F.B.I`, and so on).
	* /(\w+([-'.]\w+)\*/
		+ 영어 단어 탐색하는데 무리 없을 RegEx
		+ 다만 `F.B.I.` 처럼 끝에 puctuation이 있을 경우 두 개의 문자(`F.B.I`, ` `)로 
		  구분이 되기 때문에 단어를 읽는 코드를 작성할 때 주의할 필요가 있다. 
			```ruby
			# from [O'REILLY: Ruby Cookbook by Lucas Carlson & Leonard Richardson]
			class String
				def word_count
					frequencies = Hash.new(0)
					downcase.scan(/(\w+([-'.]\w+)*)/) { |word, ignore| frequencies[word] += 1 }
					return frequencies
				end
			end
			```
	* TODO: ruby regexp 찾아보기.

- White Spaces
  * 처음과 끝에 공백들을 제거하기 위해 `strip`을 사용.
	```ruby
	s = "            hello        ";
	s.strip					# => "hello"
	```
	  + lstrip => 왼쪽(시작점) 공백들만 제거
	  + rstrip => 오른쪽(끝 지점) 공백들만 제거
	
- Bayesian Analyzer
  * gem classifier required
	* 주어진 데이터의 빈도를 보고 확률을 계산해 어느 그룹에 속하는지 알려준다.
