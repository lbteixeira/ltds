.PHONY: test-debug
test-debug:
		./tests/build/tests/ltds-tests -s -r compact

.PHONY: test-release
test-release:
		cmake -D CMAKE_CXX_COMPILER=g++ -D PROJECT_BUILD_TESTS="ON" -D CMAKE_BUILD_TYPE="Release" -S . -B tests/build/
		cmake --build ./tests/build
		./tests/build/tests/ltds-tests -s -r compact

.PHONY: examples-debug
examples-debug:
		cmake -D PROJECT_BUILD_EXAMPLES="ON" -D CMAKE_BUILD_TYPE="Debug" -S . -B examples/build/
		cmake --build ./examples/build

.PHONY: clean
clean:
		rm -rf tests/build/*
		rm -rf examples/build/*

