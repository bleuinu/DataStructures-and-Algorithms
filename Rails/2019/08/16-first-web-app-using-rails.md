# Creating first Rails Web Application

## Rails 설치

아래의 한 줄 코드로 Rails의 설치가 가능하다.
만약 루비를 설치하지 않았다면 지난번에 작성한 [루비 설치하기](../../../../Ruby/2019/08/16.md) 문서를 참고하자

```bash
gem install rails -v 5.2.3
```

## Rails 시작
아래의 명령어를 입력하면 개발하는데 필요한 기본 디렉토리가 만들어진다.

```
rails new my_first_app
```

아무것도 모르는 현 상태에서 뭔가를 만드는건 불가능하니, 주어진 템플릿을 사용해보자.

```
cd my_first_app

rails generate scaffold car make:string model:string year:integer
```

위 작업이 끝났으면 데이터베이스를 옮겨준다.

```
rails db:migrate
```

그리고 실행.

```
rails server
```

오류가 없으면 웹을 열고 `localhost:3000/cars`를 입력.<br>
만들어진 앱을 로컬로 확인하는것이 가능 하다.
