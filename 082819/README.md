## August 28, 2019

### Java Script
- 7 data types
  * number
	* string
	* boolean
	* null
	* undefined
	* object
	* symbol

- Variables
  * 모든 숫자들은 64비트 부동소수점으로 IEEE 754를 따른다.
	  + 52 bits (Mantissa)
		+ 11 bits (Exponents)
		+ 1 bit (Sign)
	* `+`는 addition 또는 concatenation에 사용된다.
	  + 숫자 + 숫자 = 숫자
		+ 숫자 + 문자열 = 문자열
  * Numeric Strings
	  + 더하기를 제외한 모든 op들은 숫자와만 연산이 가능하기에 문자열은 자동으로 숫자로 변환되어 계산된다.

- NaN (not a number)
	* Type of Number
		+ NaN + 숫자 = NaN
		+ NaN + 문자열 = "NaN문자열"

- Infinity / -Infinity
  * 프로그램내에서 표기불가능 할 정도의 큰 수.
	```js
	let num = 2;
	while(x != Infinity)
	{
		num *= num;
	}
	```

- 진법 변환
  * 16진법을 표기하기 위해 숫자 앞에 `0x`를 붙이면 된다.
	```js
	let number = 0xFF; // number = 255
	```
	* toString을 사용하면 2~36진법으로 숫자를 변환할 수 있다.
	```js
	let num = 32;
	
	num.toString(32); // 01
	num.toString(10); // 32
	num.toString(8);  // 40
	num.toString(5);  // 112
	num.toString(2);  // 100000
	```

- Switch Range
  * switch문에서 범위 지정이 가능하다.
	```js
	switch(true)
	{
		case num>0 && num<=50:
				console.log("small");
				break;
		case num>50 && num<=80:
				console.log("medium");
				break;
		default:
				console.log("large");
	}
	```
	switch에서 받는 인자가 변수가 아닌 true라는 것을 명심한다.
