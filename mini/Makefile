.SECONDARY:

LATEST = $(shell ls | sort -n | tail -1 | cut -d '.' -f 1)

all: $(LATEST)

%mini: ../in/input%.txt ../run_%mini
	@../run_$@ < $<

../in/input%.txt:
	@pbpaste > $@ && open $@

../run_%mini: %mini.cpp
	@g++ -o $@ $<
