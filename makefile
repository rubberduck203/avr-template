all: check avr

avr:
	$(MAKE) -C src

.PHONY: size
size:
	$(MAKE) -C src $@

.PHONY: check
check:
	$(MAKE) -C test

.PHONY: clean
clean:
	$(MAKE) -C src $@
	$(MAKE) -C test $@