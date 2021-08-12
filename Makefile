all: dump

dump : dump.c
	gcc -Wall $^ -o $@

# 実行例
run: dump
	cat dump.c | ./dump

clean:
	rm -rf dump dump.o
