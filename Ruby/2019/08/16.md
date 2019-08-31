# Ruby Installation

Ubuntu 18.04.3 LTS (Bionic)을 기반으로 한다.

## Base Setting
- 리눅스 업데이트
```bash
sudo apt update && sudo apt upgrade
```

- 필요한 기본 패키지와 라이브러리 설치
```bash
sudo apt install curl git nodejs gcc make libssl-dev libreadline-dev zlib1g-dev libsqlite3-dev
```

## Ruby 설치하기
### rbenv 설치

터미널을 열고 아래의 커맨드를 입력.

```bash
git clone https://github.com/rbenv/rbenv.git ~/.rbenv

echo 'export PATH="$HOME/.rbenv/bin:$PATH"' >> ~/.bashrc
echo 'eval "$(rbenv init -)"' >> ~/.bashrc
exit
```

터미널 재실행.
```bash
mkdir -p "$(rbenv root)"/plugins
git clone https://github.com/rbenv/ruby-build.git "$(rbenv root)"/plugins/ruby-build
```

rbenv가 제대로 설치되었는지 확인해보자.

```
rbenv -v
```

버전 정보가 출력이 되면 성공적으로 설치가 완료된것이다.

### Ruby 설치
rbenv를 이용해 루비를 설치한다.

```bash
rbenv install 2.6.3 --verbose
```

설치완료 후 rbenv의 기본 루비 버전을 설정한다.
```bash
rbenv global 2.6.3
```

Ruby의 버전을 확인.

```bash
ruby -v
```
