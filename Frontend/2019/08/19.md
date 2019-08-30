## User-agent stylesheet

사용하는 웹 브라우저에 따라 다르지만 기본적으로 적용되어 있는 초기값들이 있다.<br>
예를들어 빈 html파일을 열었는데 패딩이 `0px`가 아니라 `2px`일 수도 있다는 말이다.

이런 기본 값들이 담겨있는 css파일을 user-agent stylesheet이라고 부른다.

이 값들을 완전히 초기화하기 위해 CSS에 아래와 같은 스타일을 적용할 수 있다.

```css
* {
	margin: 0px;
	padding: 0px;
}
```

`*`은 모든 선택자를 의미하며, 모든 선택자들의 마진과 패딩영역을 초기화 한다. <br>
하지만 마진과 패딩만이 아닌 다른 곳에 어떤 값이 적용되어 있는지 모르기 때문에 `resets.css`을 사용하는 것을 권장한다.

## resets.css 

아래는 meyerweb에서 제공하는 `resets.css`파일로, 이 코드를 복사해서 사용하면 된다.
```css
 /* http://meyerweb.com/eric/tools/css/reset/ 
	 v2.0 | 20110126
	 License: none (public domain)
*/

html, body, div, span, applet, object, iframe,
h1, h2, h3, h4, h5, h6, p, blockquote, pre,
a, abbr, acronym, address, big, cite, code,
del, dfn, em, img, ins, kbd, q, s, samp,
small, strike, strong, sub, sup, tt, var,
b, u, i, center,
dl, dt, dd, ol, ul, li,
fieldset, form, label, legend,
table, caption, tbody, tfoot, thead, tr, th, td,
article, aside, canvas, details, embed, 
figure, figcaption, footer, header, hgroup, 
menu, nav, output, ruby, section, summary,
time, mark, audio, video {
	margin: 0;
	padding: 0;
	border: 0;
	font-size: 100%;
	font: inherit;
	vertical-align: baseline;
}
/* HTML5 display-role reset for older browsers */
article, aside, details, figcaption, figure, 
footer, header, hgroup, menu, nav, section {
	display: block;
}
body {
	line-height: 1;
}
ol, ul {
	list-style: none;
}
blockquote, q {
	quotes: none;
}
blockquote:before, blockquote:after,
q:before, q:after {
	content: '';
	content: none;
}
table {
	border-collapse: collapse;
	border-spacing: 0;
}
```
