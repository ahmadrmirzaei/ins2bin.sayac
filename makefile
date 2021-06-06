all:
	flex -oscanner.cc scanner.l
	bison -oparser.cc parser.y
	g++ inst.cc driver.cc main.cc scanner.cc parser.cc