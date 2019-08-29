## August 16, 2019

### Web
- 모든 기기들(컴퓨터, 핸드폰, 타블렛, 등등)은 고유의 주소인 **IP address**를 가지고있다. 나와 상대방의 주소를 <b>패킷(packet)</b>에 담아 <b>라우터(router)</b>와 <b>모뎀(modem)</b>을 통해 이 신호를 변환한 후 <b>ISP</b>를 통해 <b>서버</b>에 전달하게 된다. 그러면 이 서버가 직접적으로 연결되어 있는 인터넷을 통해 상대방의 컴퓨터와 연결되어 있는 ISP와 Router를 통해 패킷을 보내게 된다. 
  * 라우터 = 길잡이. 패킷의 가이드 역할
  * 요청한 데이터 = 수 많은 패킷으로 쪼개 보낸 후 클라이언트에서 하나로 합침.
  * IP Checker: https://ipinfo.info/html/ip_checker.php
- <b>웹 페이지</b>(Web Page) - 단일 페이지
- <b>웹 사이트</b>(Web Site) - 복수의 페이지
- <b>웹 서버</b>(Web Server) - 복수의 웹사이트
- <b>웹 브라우저</b>(Web Browser) - 컴퓨터 프로그램; 웹 서버의 주소와 웹 페이지들을 화면에 표현한다.
  * 사용하고 있는 웹 브라우저 확인: http://www.thismachine.info
  
### Rails
 - <b>rbenv</b>로 ruby 설치: [Link](https://www.theodinproject.com/courses/web-development-101/lessons/installing-ruby?ref=lnav)
   * rvm이랑 겹쳐서 그런가 Jekyll 블로그 로컬에서 실행안되는 문제가 있었으나 젬을 다시 설치하니 됐다:<br /> `gem install jekyll` 
 - rails 어플 초기 셋업
   * `rails new <app-name>`
     + [The Odin Project](https://www.theodinproject.com/courses/web-development-101/lessons/your-first-rails-application?ref=lnav)가 새로 업데이트된 `Rails 6.0.0`과 맞지 않아서 문제가 생긴다. <br /> `rails 5.2.3`버젼을 사용하자: `rails _5.2.3_ new <app-name>`.
 - [Heroku](https://id.heroku.com/)에 deploy 하는 법
 
### mkdir -p
- `mkdir -p /a/b/c/` 
  * 디렉토리를 중첩으로 만들수 있다.
