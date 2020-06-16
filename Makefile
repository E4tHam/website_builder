# Makefile

# [target]: [Dependencies]
#	[commands {separated by tab}]

CXX=g++
DEPENDENCIES=assembler/main.o assembler/website.o assembler/page.o assembler/confInterpreter.o
EXE=build

all: clean ${EXE}

${EXE}: ${DEPENDENCIES}
	${CXX} -std=c++11 -o $@ $^

# $@ ··· [target]
# $^ ··· {Dependencies}

clean:
	rm -f **/*.o ${EXE}
