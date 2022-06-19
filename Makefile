.SECONDARY:
.PHONY: mini

MAX = $(shell echo `ls normal | wc -l`)
NEXT = $(shell expr $(MAX) + 1)

all: $(MAX)

%: in/input%.txt run_normal%
	@./run_normal$@ < $<

in/input%.txt:
	@pbpaste > $@ && open $@

run_normal%: normal/%-*.cpp
	@g++ -o $@ $<

new: in/input$(NEXT).txt
	@open `cp -nv template.cpp normal/$(NEXT)-$(id).cpp | cut -d ' ' -f 3`

mini: normal/$(MAX)-*.cpp in/input$(MAX).txt
	@open `cp -nv $< mini/$(MAX)mini.cpp | cut -d ' ' -f 3`

clean:
	rm run_*
