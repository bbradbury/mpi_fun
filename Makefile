.PHONY: DEFAULT cmake

DEFAULT: all

% :
	$(MAKE) -C build/ $@

cmake:
	cd build/ && cmake ..
#	cd build/ && CXX="$(HOME)/.vim/bundle/clang_complete/bin/cc_args.py g++" cmake ..

clean-build:
	rm -rf build/*
