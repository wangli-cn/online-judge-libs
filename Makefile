.PHONY: all clean

all: build

build:
	$(MAKE) -C sorting/Makefile

book:
	pdflatex book

clean:
	-rm -f *.log *.aux *.lol *.toc
