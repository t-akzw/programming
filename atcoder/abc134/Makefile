override CC := /usr/local/bin/g++
CFLAGS := -std=c++11

a:
	$(CC) -o a.out $(CFLAGS) a.cpp
b: 
	$(CC) -o b.out $(CFLAGS) b.cpp
c:
	$(CC) -o c.out $(CFLAGS) c.cpp
d: 
	$(CC) -o d.out $(CFLAGS) d.cpp 
dd: 
	$(CC) -o dd.out $(CFLAGS) dd.cpp 
e:
	$(CC) -o e.out $(CFLAGS) e.cpp
f: 
	$(CC) -o f.out $(CFLAGS) f.cpp
template:
	$(CC) -o template.out $(CFLAGS) template.cpp
cpa:
	cp template.cpp a.cpp
cpb:
	cp template.cpp b.cpp
cpc:
	cp template.cpp c.cpp
cpd:
	cp template.cpp d.cpp
cpe:
	cp template.cpp e.cpp
cpf:
	cp template.cpp f.cpp
exa:
	./exec.sh a
exb:
	./exec.sh b
exc:
	./exec.sh c
exd:
	./exec.sh d
exdd:
	./exec.sh dd
exe:
	./exec.sh e
exf:
	./exec.sh f
ext:
	./template.out
clean:
	$(RM) *.out
