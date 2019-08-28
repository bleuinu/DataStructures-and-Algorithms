## August 27, 2019

### Google Homepage Clone Project
- 상단에 오른쪽 메뉴를 만들때 float을 사용해서 어거지로 margin과 padding 주면서 비슷하게 만들기는 했는데
  `grid` 랑 `flex-box`를 사용하면 훨씬 자연스럽게 만들 수 있는 것 같다. 다음에 제대로 사용해보도록 하자.

- `search by voice` 툴팁을 만들기 위해 `visibility: hidden`을 사용했다. 마이크 이미지에 hover를 하면 이 글이 보여지도록 하려고 
	```html
	<img ...>
	<span class=".tooltip">Search by voice</span>
	```
	```css
	img:hover .tooltip {
		visibility: visible;
	}
	```
	을 했는데 동작하지 않았다. 제대로 동작하기 위해서는 `img`가 `.tooltip`을 감싸주고 있는 형태여야 했다. 하지만 `img` 태그로는 불가능하니 `div` 태그로 두 개를 묶어주었다.
	```html
	<div class=".mic-img">
		<img ...>
		<span class=".tooltip">Search by voice</span>
	</div>
	```
