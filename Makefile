# .SECONDARY: Prevents the automatic deletion of executable
#   files created by this makefile.
.SECONDARY:

# MAX: The number of files in the normal directory. These files
#   are numbered from one to MAX, and the file with the highest
#   number is the most recent.
MAX = $(shell echo `ls normal | wc -l`)

# NEXT: The successor of MAX. Used to name new normal c++ files.
NEXT = $(shell expr $(MAX) + 1)

# all: Runs the most recent normal executable file.
all: $(MAX)

# %: Runs the normal executable file which corresponds to this
#   number. The input file is redirected to stdin.
%: in/input%.txt run_%normal
	@./run_$@normal < $<

# in/input%.txt: Creates this text file from the contents of the
#   clipboard, and then opens it.
in/input%.txt:
	@pbpaste > $@ && git add $@ && open $@

# run_%normal: Builds this numbered executable file from its
#   corresponding normal c++ file.
run_%normal: normal/%-*.cpp
	@clang++ -Wall -o $@ $<

# new: Copies the template c++ file into the normal folder
#   renamed with NEXT and a given id, e.g. "make new id=4A".
#   The c++ file is then opened, and a corresponding input file
#   is created if necessary.
new: in/input$(NEXT).txt
	@new=normal/$(NEXT)-$(id).cpp  ;\
	cp -n template.cpp $$new       ;\
	git add $$new                  ;\
	open $$new

# mini: Copies the most recent normal c++ file into the mini
#   folder. The file is renamed and opened.
mini: normal/$(MAX)-*.cpp
	@mini=mini/$(MAX)mini.cpp      ;\
	cp -n $< $$mini                ;\
	git add $$mini                 ;\
	open $$mini

# fav: Renames the most recent normal c++ file to include the
#   problem's given difficulty, e.g. "make fav tag=800". A link
#   to the problem is added to a list of favorites in the
#   README.md file.
fav: normal/$(MAX)-*.cpp
	@id=$$(echo $< | cut -d '-' -f 2 | cut -d '.' -f 1)  ;\
	git mv $< normal/$(MAX)-$$id-$(tag).cpp              ;\
	echo "$(tag): <https://codeforces.com/problemset/problem/$${id%?}/$${id:$${#id}-1:1}>\n" >> README.md

# clean: Removes executable files that were created by this
#   makefile and mini/Makefile.
clean:
	@rm -v run_*
