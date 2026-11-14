CXX = icpx -fsycl -std=c++17
WARNINGS = -Wall -Wextra -Werror -pedantic -Wshadow -Wnon-virtual-dtor -Wformat-security -Wimplicit-fallthrough -Wunreachable-code
PATH_HOME = ${shell pwd}

# ------------------------------------ #
# 																		 #
# Scripts for src_amdahls_law program. #
#																			 #
# ------------------------------------ #
.PHONY: build-amdahls-law run-amdahls-law
HEADERS_AMDAHLS_LAW = -I${PATH_HOME}/src_amdahls_law/daxpy
SOURCE_FILES_AMDAHLS_LAW = ${wildcard ./src_amdahls_law/daxpy/*.cpp}
build-amdahls-law:
	${CXX} ${WARNINGS} ${HEADERS_AMDAHLS_LAW} ./src_amdahls_law/main.cpp ${SOURCE_FILES_AMDAHLS_LAW} -o ./build/src_amdahls_law
run-amdahls-law: build-amdahls-law
	clear
	./build/src_amdahls_law --operation=${operation}

# --------------------------------- #
# 																	#
# Scripts for src_calculus program. #
#																		#
# --------------------------------- #
.PHONY: build-calculus run-calculus
HEADERS_CALCULUS = -I${PATH_HOME}/src_calculus
SOURCE_FILES_CALCULUS = ${wildcard ./src_calculus/json/*.cpp} ${wildcard ./src_calculus/plotter/*.cpp}
build-calculus:
	${CXX} ${WARNINGS} ${HEADERS_CALCULUS} ./src_calculus/main.cpp ${SOURCE_FILES_CALCULUS} -o ./build/src_calculus
run-calculus: build-calculus
	clear
	./build/src_calculus --example=${example}

# ------------------------------ #
#																 #
# Scripts for src_daxpy program. #
# 															 #
# ------------------------------ #
.PHONY: build-daxpy run-daxpy
HEADERS_DAXPY = -I${PATH_HOME}/src_daxpy/daxpy
SOURCE_FILES_DAXYPY = ${wildcard ./src_daxpy/daxpy/*.cpp}
build-daxpy:
	${CXX} ${WARNINGS} ${HEADERS_DAXPY} ./src_daxpy/main.cpp ${SOURCE_FILES_DAXYPY} -o ./build/src_daxpy
run-daxpy: build-daxpy
	./build/src_daxpy

# ------------------------------ #
# 															 #
# Scripts for src_hello program. #
# 															 #
# ------------------------------ #
.PHONY: build-hello run-hello
build-hello:
	${CXX} ${WARNINGS} ./src_hello/main.cpp -o ./build/src_hello
run-hello: build-hello
	./build/src_hello
