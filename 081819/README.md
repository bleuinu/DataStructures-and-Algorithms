## August 18, 2019

## Bash
  * TIL을 위한 간단한 [스크립트](https://github.com/myoiwritescode/TIL/blob/master/today)를 구현했다. 오늘의 날찌로 디렉토리를 만들고 그 안에 `README.md`를 만드는 간단한 스크립트. 
    + 다음과 같은 방식으로 오늘의 날짜를 표시 할 수 있다.
	```bash
	now=`date +'%m/%d/%Y'
    echo "$now"
    ```

## Front-end
- [Margin Collapse](https://discuss.codecademy.com/t/collapsing-margins/365328)
  + 사진 두 개가 있고 이 사진들의 가로폭 margin을 10px로 둘 경우, 두 사진 가운데 가로폭은 10px + 10px = 20px가 된다. 하지만 세로폭의 경우는 다르다.
  세로폭의 경우 첫 번째 사진의 `margin-bottom: 10px`이고 두 번째 사진의 `margin-top: 20px`일 경우, 가장 큰 margin을 고정폭으로 만들어버려 30px가 아닌 20px가 margin이 된다.
- overflow
  * scroll
  * hidden
  * visible
- Resetting Defaults
  * User agen stylesheets
  ```css
  * {
    margin: 0px;
    padding: 0px;
  }
  ```
