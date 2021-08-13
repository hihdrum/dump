all: dump

dump: dump.ros
	ros build $^

# 実行例
run: dump
	cat dump.ros | ./dump

clean:
	rm -rf dump

