INCLUDIR = ./inc
SRCDIR = ./src
OUTDIR = outdir
OBJECTSDIR = $(OUTDIR)/objects
MKDIR_P = mkdir -p

all: create_out_folder basic_count_lib
	$(CXX) -shared -o $(OUTDIR)/libcountclock.so $(wildcard $(OBJECTSDIR)/*.o)

create_out_folder:
	$(MKDIR_P) $(OBJECTSDIR)

basic_count_lib:
	$(CXX) -c -o $(OBJECTSDIR)/countclock.o -I$(INCLUDIR) $(SRCDIR)/countClockCycles.cpp

clean:
	rm -rf $(OUTDIR)