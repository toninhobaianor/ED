{ pkgs }: {
	deps = [
		pkgs.valgrind
  pkgs.clang_12
		pkgs.cmake
		pkgs.gdb
	];
}