include ../../makefile_defs.mk
BALANCE_LOCAL = ../../local/
RHIC_HOME = ${MADAI_HOME}/rhic

INCLUDE = -I ${BALANCE_LOCAL}/include -I ${MADAI_INSTALLDIR}/include/madai -I ${MADAI_GSLPATH}/include -I /usr/include

LIBRARY = -L ${BALANCE_LOCAL}/lib -L ${MADAI_GSLPATH}/lib -L ${MADAI_INSTALLDIR}/lib/madai -L /usr/lib

corallibs :
	make -C ${RHIC_HOME}/coral install

b3dlibs :
	make -C ${RHIC_HOME}/b3d2 install

ballibs : 
	make -C ../../software install

statlibs :
	make -C ../rhicstat install

balance : ballibs corallibs b3dlibs
	${MADAI_CPP} ${MADAI_CFLAGS} balmain.cc ${INCLUDE} ${LIBRARY} -lbalance -lb3d -lcoralutils -lgsl -lgslcblas -larmadillo -o balance

mixed : ballibs corallibs b3dlibs
	${MADAI_CPP} ${MADAI_CFLAGS} mixedmain.cc ${INCLUDE} ${LIBRARY} -lbalance -lb3d -lcoralutils -lgsl -lgslcblas -larmadillo -o mixed

analyze : analyze.cc corallibs
	${MADAI_CPP} ${OPT} analyze.cc -o analyze

rhicstat : rhicstatmain.cc statlibs corallibs
	${MADAI_CPP} rhicstatmain.cc ${MADAI_CFLAGS} ${INCLUDE} ${LIBRARY} -lcoralutils -lgsl -lgslcblas -lrhicstat -larmadillo -o rhicstat

getparsamples : getparsamplesmain.cc statlibs corallibs
	${MADAI_CPP} getparsamplesmain.cc ${MADAI_CFLAGS} ${INCLUDE} ${LIBRARY} -lcoralutils -lgsl -lgslcblas -larmadillo -lrhicstat -o getparsamples