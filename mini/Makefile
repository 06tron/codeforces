# .SECONDARY: Prevents the automatic deletion of executable
#   files created by this makefile.
.SECONDARY: $(wildcard ../run_*mini)

# all: Runs the most recent mini executable file.
all: $(shell ls | sort -n | tail -1 | cut -d '.' -f 1)

# %mini: Runs the mini executable file which corresponds to
#   this file name. The input file is redirected to stdin.
%mini: ../in/input%.txt ../run_%mini
	@../run_$@ < $<

# ../in/input%.txt: Creates this text file from the contents of
#   the clipboard, and then opens it.
../in/input%.txt:
	@pbpaste > $@ && git add $@ && open $@

# ../run_%mini: Builds this numbered executable file from its
#   corresponding mini c++ file.
../run_%mini: %mini.cpp
	@clang++ -Wall -o $@ $<
