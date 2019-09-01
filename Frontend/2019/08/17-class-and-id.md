## Class와 ID 선택자의 차이

우선 CSS에서 두 선택자들을 표현하는 방법들을 살펴보자.
```css
#top-menu {
	background-color: blue;
	margin: 5px 10px;
}

.red-big-font {
	background-color: red;
	font-size: 36px;
}
```

CSS에서 ID는 `#` 심볼을, Class는 `.` 심볼이 앞에 붙는다.

이렇게 지정한 스타일은 HTML에서 각각 `class`와 `id`로 부여할 수 있다.

```html
<body>
    <header>
        <div id="top-menu">
        	<-- navigation bar -->
        </div>
    </header>
    <main>
        <p>
        	This word is <span class="red-big-font">BIG</span>.
        	This apple is <span class="red-big-font">HUGE</span>
        </p>
    </main>
</body>
```

중요한 점은 ID는 페이지 내에서 단 한 개의 태그에만 적용시킬 수 있고, Class는 한 개 이상의 태그들에 적용할 수 있다는 점이다.
