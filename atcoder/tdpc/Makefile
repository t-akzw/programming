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
e:
	$(CC) -o e.out $(CFLAGS) e.cpp
f: 
	$(CC) -o f.out $(CFLAGS) f.cpp
i: 
	$(CC) -o i.out $(CFLAGS) i.cpp
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
exe:
	./exec.sh e
exf:
	./exec.sh f
exi:
	./exec.sh i
ext:
	./template.out
clean:
	$(RM) *.out