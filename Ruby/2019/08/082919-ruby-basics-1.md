# Ruby Basics 1

- Ruby는 모든 것이 개체(object)다.
- 문자열의 경우 C/C++에서는 연속된 문자를 의미하지만 루비에서는 연속된 바이트를 의미한다.

## 메소드 이름
- `!`가 붙어있는 메소드는 본래의 데이터의 영향을 끼친다.
	```ruby
	str = "Hello";
	str.upcase      # => "HELLO"
	puts str        # => "Hello"

	str.upcase!     # => "HELLO"
	put str         # => "HELLO"
	```

- _predicates_ (불리언 값을 반환하는 메소드)에는 `?`가 붙는다.
	```ruby
	str = ''
	str.empty?      # => true

	str = "Hello"
	str.empty?      # => false
	```

## 문자열
- 'Here Document' 이라고 불리우며 
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
	문자열 끝에 새로운 문자열을 이어 붙힌다.
	```ruby
	str = ''
	str << "hello"
	puts str          # => "hello"
	```

	아래의 경우 비효율적인 면이 있다.
	```ruby
	fname = "Jii"
	lname = "Yoo"
	str << "Hello " << "#{fname} #{lname}"
	puts str        # => "Hello Jii Yoo"
	```

  위 코드가 비효율적인 이유는 `"#[fname} #{lname}"`을 담을 공간을 일시적으로 만들어 보관하기 때문이다.<br>
  아래와 같이 하는 것을 권장한다.

  ```ruby
  str << "Hello " << fname << ' ' << lname;
  ```

## 문자열의 변수 치환하기

변수를 치환하는 방법에는 두 가지가 있다.
1. C와 같은 printf 스타일
2. PHP와 같은 ERB templates

### printf-style

```c
printf("Hello, %s\n", "Jii Yoo");
```

위 코드를 루비로 표현하면 아래와 같다.

```ruby
template = "Hello, %s"
puts template % "Jii Yoo"
```

만약 치환할 편수가 한 개 이상이라면 배열을 값으로 넘겨준다.

```ruby
template = "Today's date: (%4d-%02d-%02d)"
template % [2019, 8, 29]
```

### ERB templates
```ruby
require 'erb'

template = ERB.new %q{Hello, <%= name %>}
name = "Jii Yoo"
template.result    # 콘솔의 경우 template.result(binding)
```

## 배열
보통 배열이라 하면 같은 자료형의 데이터를 담는 공간을 의미하는데, <br>
Ruby에서는 여러 데이터 타입이 섞여도 된다.

```ruby
arr = [1, "str", true, [1,2,3]]
```

데이터가 오로지 문자열인 경우 간단한 방법이 존재한다.

```ruby
arr = %w{a b c d}    # => ["a", "b", "c", "d"]
```

### 새로운 데이터 추가

배열에 새로운 데이터를 추가할때는 `<<` 연산자를 사용한다.

```ruby
arr = []       # => []
arr << 5       # => [5]
arr << 'five'  # => [5, "five"]

# 무한 배열
arr << arr     # => [5, "five", [...]]
```

### 배열을 이용한 집합 연산

```ruby
a = [1,3,5]
b = [1,3,4,6]

# Union
a | b      # => [1,3,4,5,6]

# Intersection
a & b      # => [1,3]

# Difference
a - b      # => [5,4,6]
```

XOR같은 경우 `a ^ b` 보다 `(a|b) - (a&b)`를 하는게 효율적이라고 한다.


## Hash

Ruby에서 해시는 문자열과 심볼을 이용하여 만들 수 있다.

```ruby
# 문자열 이용
people = {
  "James" => "Student",
	"Kevin" => "Cook",
	"Yebin" => "Designer"
}

# 심볼 이용
scores = {
	:James => 58,
	:Kevin => 60,
	:Yebin => 55
}
```

메모리와 시간을 효율적으로 사용하기 위해서는 문자열보다 심볼을 사용하는 것이 맞다.

일단 심볼의 경우 해시 값은 바로 그 심볼의 `object_id`가 된다. 반면 문자열의 경우,<br>
같은 값을 가진 문자열이여도 `object_id`가 다르기 때문에 매번 계산을 해야된다 = 메모리 누적.

```ruby
:symbol.object_id    # => 376988
:symbol.object_id    # => 376988
:symbol.object_id    # => 376988

"name".object_id     # => 46978076514880
"name".object_id     # => 46978076508560
"name".object_id     # => 46978076526700
```

심볼은 단 하나의 인스턴스만 있기 때문에 고유의 `object_id`를 가지지만, <br>
문자열은 매번 새로운 인스턴스를 생성.


