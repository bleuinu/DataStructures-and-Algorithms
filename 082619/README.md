## August 26, 2019

## Front-end

### Sprite Sheets
- Googlo 홈페이지 만들기를 하면서 dev tools를 사용해 이미지들을 가져왔는데, 여러개의 아이콘이
있는 스프라이트 이미지였다. 이를 분할하기 위해서 아래와 같이 한다.
```css
object-fit: none;
object-position: -132px -37px;
width: 30px;
height: 30px;
```
`object-position`이 스프라이트 이미지의 시작점을 의미한다. 즉 여기서는 좌표(132, 37)에서 
30x30 크기의 이미지를 가져온다.

### Comments
- CSS에서 주석다는 법을 몰랐는데 보니까 C 초기 버전의 주석 방법과 같았다.
```css
/* comment */
```

### Box Model
- 컨텐츠를 페이지 중간으로 정렬하는데 박스모델에 이해가 부족한 것 같다.
```css
margin: 0 auto;
```
위 처럼 할 경우 페이지 중앙으로 정렬이 되야하는데 제대로 동작하지 않는다.
이유는 width가 정의되지 않아서다. 길이가 정의되지 않으면 자동으로 페이지
총 길이의 크기를 가져, 중간으로 정렬이 될 수가 없다.
```css
width: 100px;
margin: 0 auto;
```

### Position
- relative, absolute, fixed?
- `fixed`를 제외한 두 개가 정확히 뭘 하는지 아직 이해가 부족하다. 다시 정의를 찾아보고 제대로 이해하자.
