all: dump

dump : dump.rs
	rustc  $^

# 実行例
run: dump
	cat dump.rs | ./dump

clean:
	rm -rf dump
