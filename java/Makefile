all: dump

dump : Dump.class
	echo "java Dump" > $@
	chmod u+x $@

Dump.class : Dump.java
	javac $^

run: dump
	cat Dump.java | ./dump

clean:
	rm -rf dump Dump.class
