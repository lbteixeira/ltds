.PHONY: test-debug
test-debug:
		cmake -D CMAKE_CXX_COMPILER=g++ -D PROJECT_BUILD_TESTS="ON" -D CMAKE_BUILD_TYPE="Debug" -S . -B tests/build/
		cmake --build ./tests/build
		./tests/build/tests/ltds-tests -s -r compact

.PHONY: examples-debug
examples-debug: debug
		cmake -D PROJECT_BUILD_EXAMPLES="ON" -D CMAKE_BUILD_TYPE="Debug" -S . -B examples/build/
		cmake --build ./examples/build

.PHONY: examples-release
examples-release: release
		cmake -D PROJECT_BUILD_EXAMPLES="ON" -D CMAKE_BUILD_TYPE="Release" -S . -B examples/build/
		cmake --build ./examples/build

.PHONY: clean-debug
clean-debug:
		rm -rf build/debug/*

.PHONY: clean-release
clean-release:
		rm -rf build/release/*

.PHONY: clean-test
clean-test:
		rm -rf tests/build/*

.PHONY: clean-examples
clean-examples:
		rm -rf examples/build/*

.PHONY: clean-all
clean-all:
		rm -rf build/debug/*
		rm -rf build/release/*
		rm -rf tests/build/*
		rm -rf examples/build/*

