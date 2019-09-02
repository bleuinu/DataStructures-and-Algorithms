# JavaScript 기초 (2)

## Functions
### 인자의 기본 값
- old
  ```js
	```

- modern
  ```js
	```

### 함수의 이름 == 주석
함수는 한 개의 작업을 담당한다. 고로 함수의 이름만 보고 대충 무슨 일을 하는지 이해할 수 있어야 한다.

```js
function a(n) {
	return n*2;
}
```

위에서 정의한 함수의 이름은 `a`다. 함수의 이름만 봐서는 무슨 일을 하는지 알 수가 없다. <br>
코드를 봐도, 2로 곱하는 건 알겠는데 뭐 때문에 곱하는 건지 이해하기 어렵다.

```js
function double(n) {
	return n*2;
}
```

하지만 함수의 이름이 `double`이라면 명확하다. <br>
값을 두 배로 만들어야 하니 2로 곱한다는 것 또한 이해할 수 있다.

### 함수 구현 방법

- Function Declaration
  ```js
  function hello() {
  	console.log("Hello, World!");
	}
  ```   

- Function Expression
  ```js
  let hello = function() {
    alert("Hello, World!");
	};
  ```

- Arrow Functions

```js
let double = n => n*2;
```

위 코드를 평범하게 작성하면 아래와 같다.

```js
let double = function(n) {
	return n*2;
}

/* or */
function double(n) {
	return n;
}
```

인자가 없을 경우, 공백의 괄호를 사용한다.

```js
let welcome = () => "Hello, World!";

let welcome = function welcome() {
	return "Hello, World!"
}
```
