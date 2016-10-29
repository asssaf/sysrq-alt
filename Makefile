BINARY=sysrq-alt
SRC=src/sysrq-alt.c
prefix=/usr/local

BINARY:
	$(CC) -o "$(BINARY)" "$(SRC)"

install:
	install -D -m 0755 "$(BINARY)" "$(DESTDIR)/$(prefix)/bin"

clean:
	rm "$(BINARY)"
