# Java Script 기초 (1)

## 7개의 데이터 타입
### number

```js
let n = 123;
n = 12.345;
```

* 모든 숫자들은 64비트 부동소수점(IEEE 754)을 따른다.
  + 52 bits (Mantissa)
  + 11 bits (Exponents)
  + 1 bit (Sign)
- NaN (not a number)
  * NaN또한 number 타입이다.
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
#### 진법 변환
* 16진법을 표기하기 위해 숫자 앞에 `0x`를 붙인다.

```js
let number = 0xFF; // number = 255
```

* toString을 사용하면 2~36진법으로 숫자를 변환할 수 있다.
```js
let num = 32;

num.toString(32); // 01
num.toString(10); // 32
num.toString(8);  // 40
```

### string
```js
let fname = "Jii";
let lname = 'Yoo';
let str = `Hello, ${fname + ' ' + lname}!`
```

자바스크립트에서는 문자열을 세 가지 방법으로 나타낼 수 있다.
1. `"Hello"` 쌍따옴표
2. `'Hello'` 단일 따옴표
3. `\`Hello\`` 역따옴표

1번과 2번의 차이는 없다. <br>
3번의 경우는 확장된 기능이 있는데 문자열 안에 `${..}`을 사용해서 변수와 식을 나타낼 수 있다.

* `+`는 숫자 더하기와 문자열 결합에 사용된다.
  + 숫자 + 숫자 = 숫자
  + 숫자 + 문자열 = 문자열
* Numeric Strings
  + 더하기를 제외한 모든 연산자들은 숫자와의 연산만이 가능하기에 문자열은 자동으로 숫자로 치환되어 계산된다.

### boolean
```js
let str = "";
let isEmpty = str.length == 0;  /* true */

str = "hello";
isEmpty = str.length == 0;  /* false */
```

`true`와 `false`의 값만 가지는 데이터 타입.

### null

```js
let age = null;
```

언매니지드 언어의 null은 보통 <i>"가리키는 포인터가 없음"</i> 또는 <i>"존재하지 않는 개체의 참조"</i>를 표현하기 위해<br>
사용되지만 자바스크립트의 null은 "무(無)", "nothing",  또는 "알 수 없는 값"을 의미한다.

### undefined

```js
let x;
alert(x);  /* undefined */
```

단어 그대로 define 되어있지 않다는 의미로, 선언만 하고<br>
값을 대입하지 않은 경우(또는 일부러 undefined를 대입 한 경우), 해당 변수는 undefined의 타입을 갖는다.

### Objects and Symbols
위에서 설명한 데이터 타입들과 다르게 `object`는 원시형 타입은 아니지만, 기본 7개의 타입 중 하나다.<br>
`symbol`타입은 각 개체의 고유식별자를 만들때 사용된다.

<hr>

## typeof 연산자

`typeof`연산자를 사용해 데이터의 타입을 확인 할 수 있다.

```js
typeof 2;         /* "number" */
typeof 'Myoi';    /* "string" */
typeof true;      /* "boolean" */
typeof undefined; /* "undefined" */
typeof Math;      /* "object" */
typeof null;      /* "object" */
```

`null`의 타입으로 `object`가 반환되는데 이는 틀린것이며 언어 쪽 문제라고 한다.
