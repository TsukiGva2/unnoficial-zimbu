BIN = measure true_zimbu true_c true_python.pyc True.class true_go

all: $(BIN)

clean:
	rm $(BIN)

measure: measure.zu
	zimbu measure.zu

true_zimbu: true_zimbu.zu
	zimbu --ccarg="-O2" true_zimbu.zu

true_c: true_c.c
	cc true_c.c -O2 -o true_c

true_python.pyc: true_python.py python_compile.py
	python python_compile.py

True.class: true_java.java
	javac true_java.java

# For instuctions on getting "go": http://golang.org/doc/install.html
# You need to link "go" go "8g" or "6g" and "golink" to "8l" or "6l".
true_go: true_go.go
	go true_go.go
	if test -r true_go.6; then golink -o true_go true_go.6; else golink -o true_go true_go.8; fi


# Using Zimbu to spread work over threads.
citycount: citycount.zu
	zimbu --ccarg="-O2" citycount.zu

# Compute digits of Pi.
pi: pi.zu
	zimbu --ccarg="-O2" pi.zu -x
