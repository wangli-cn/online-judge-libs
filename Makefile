.PHONY: all clean

all: dotMnO2

dotMnO2:
	pdflatex dotMnO2

clean:
	-rm -f *.log *.aux *.lol *.toc
