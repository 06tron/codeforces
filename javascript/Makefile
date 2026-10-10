# Ensures that recipes with the 'force' prerequisite will run
.PHONY: force

# Prevents automatic deletion of files created by this Makefile
.SECONDARY:

# Reduces clutter when running 'make -d'
.SUFFIXES:
MAKEFLAGS += -rR

# Name of the most recently updated file in the src directory
LATEST = $(shell ls -t src | head --lines=1)

# Runs the most recently updated .js file
all: src/$(LATEST)

# Runs the target .js file with Node.js
src/%.js: ../in/js-input-%.txt force
	sub=submit.js ;\
	cat asciiIntReader.min.js $@ > $$sub ;\
	node $$sub < $<

# Creates input file using copied text
../in/js-input-%.txt:
	pbpaste > $@
	git add $@
	open $@

start-%.json:
	jq 'now | round' --null-input > $@

# Creates new .js file with template.js
%.js: ../in/js-input-%.txt start-%.json
	new=src/$@ ;\
	cp -i testcase-loop.js $$new ;\
	git add $$new ;\
	open $$new

times-%.json:
	jq --from-file update-times.jq latest-times.json --arg id $* --slurpfile start start-$*.json --argjson bytes $(shell wc -c < src/$*.js) --raw-output > $@

end: times-$(LATEST)on
	cp $< latest-times.json && rm start-$(LATEST)on $<
