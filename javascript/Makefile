# Prevents automatic deletion of files created by this Makefile
.SECONDARY:

# Name of the most recently updated file in the src directory
LATEST = $(shell ls -t src | head --lines=1)

# Runs the most recently updated .js file
all: src/$(LATEST)

# Runs the target .js file with Node.js
src/%.js: ../in/js-input-%.txt
	node $@ < $<

# Creates input file using copied text
../in/js-input-%.txt:
	pbpaste > $@ && git add $@

# Creates new .js file with template.js
%: ../in/js-input-%.txt
	@new=src/$@.js ;\
	cp -i template.js $$new ;\
	date +"// Began: %s" >> $$new ;\
	git add $$new ;\
	open $$new

# Appends timestamp to most recent .js file
end:
	date +"// Ended: %s" >> src/$(LATEST)
