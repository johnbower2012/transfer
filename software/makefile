include ../makefile_defs.mk
BALANCE_LOCAL = ../local
#ROOT_ROOT = /usr/local/root/lib

#ROOT_LIBS = $(shell root-config --libs)
#ROOT_INCDIR = $(shell root-config --incdir)

INCLUDE = -I /usr/include -I ${BALANCE_LOCAL}/include -I ${MADAI_INSTALLDIR}/include/madai -I ${MADAI_GSLPATH}/include -I/usr/local/include
#-I${ROOT_INCDIR}

LIBRARY = -L /usr/lib -L ${BALANCE_LOCAL}/lib -L ${MADAI_GSLPATH}/lib -L ${MADAI_INSTALLDIR}/lib/madai
#-L${ROOT_ROOT}

HEADERS = ${BALANCE_LOCAL}/include/bal.h ${BALANCE_LOCAL}/include/distributions.h

BAL_OBJECTS = build/bal_subs.o build/acceptance.o build/acceptance_cheap.o build/calcbf.o build/calcmixed.o build/acceptance_STAR.o build/distributions.o
# left off build/acceptance_ALICE.o 

install : ${HEADERS} ${BALANCE_LOCAL}/lib/libbalance.a

${BALANCE_LOCAL}/lib/libbalance.a : ${BAL_OBJECTS}
	rm -f ${BALANCE_LOCAL}/lib/libbalance.a;\
	ar -ru ${BALANCE_LOCAL}/lib/libbalance.a ${BAL_OBJECTS}

build/bal_subs.o : src/bal_subs.cc ${HEADERS}
	${MADAI_CPP} ${MADAI_CFLAGS} -c src/bal_subs.cc -o build/bal_subs.o ${INCLUDE}

build/calcbf.o : src/calcbf.cc ${HEADERS}
	${MADAI_CPP} ${MADAI_CFLAGS} -c src/calcbf.cc -o build/calcbf.o ${INCLUDE}

build/calcmixed.o : src/calcmixed.cc ${HEADERS}
	${MADAI_CPP} ${MADAI_CFLAGS} -c src/calcmixed.cc -o build/calcmixed.o ${INCLUDE}

build/acceptance.o : src/acceptance/acceptance.cc ${HEADERS}
	${MADAI_CPP} ${MADAI_CFLAGS} -c src/acceptance/acceptance.cc -o build/acceptance.o ${INCLUDE}

build/acceptance_cheap.o : src/acceptance/acceptance_cheap.cc ${HEADERS}
	${MADAI_CPP} ${MADAI_CFLAGS} -c src/acceptance/acceptance_cheap.cc -o build/acceptance_cheap.o ${INCLUDE}

build/distributions.o : src/distributions.cc ${HEADERS}
	${MADAI_CPP} ${MADAI_CFLAGS} -c src/distributions.cc -o build/distributions.o ${INCLUDE}

#build/acceptance_ALICE.o : src/acceptance/acceptance_ALICE.cc ${HEADERS}
#	${MADAI_CPP} ${MADAI_CFLAGS} -c src/acceptance/acceptance_ALICE.cc -o build/acceptance_ALICE.o ${INCLUDE}

build/acceptance_STAR.o : src/acceptance/acceptance_STAR.cc ${HEADERS}
	${MADAI_CPP} ${MADAI_CFLAGS} -c src/acceptance/acceptance_STAR.cc -o build/acceptance_STAR.o ${INCLUDE}

clean :
	rm -f balance ${BALANCE_LOCAL}/lib/libbalance.a build/*.o ${BALANCE_LOCAL}/include/bal.h ${BALANCE_LOCAL}/include/distributions.h

${BALANCE_LOCAL}/include/bal.h : src/bal.h
	cp -f src/bal.h ${BALANCE_LOCAL}/include/

${BALANCE_LOCAL}/include/distributions.h : src/distributions.h
	cp -f src/distributions.h ${BALANCE_LOCAL}/include/
