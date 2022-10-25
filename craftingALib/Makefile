INCLUDIR = ./inc
SRCDIR = ./src
OUTDIR = outdir
OBJECTSDIR = $(OUTDIR)/objects
MKDIR_P = mkdir -p

all: create_out_folder basic_calc_lib
	$(CXX) -shared -o $(OUTDIR)/libcalculator.so $(wildcard $(OBJECTSDIR)/*.o)

create_out_folder:
	$(MKDIR_P) $(OBJECTSDIR)

basic_calc_lib:
	$(CXX) -c -o $(OBJECTSDIR)/calculator.o -I$(INCLUDIR) $(SRCDIR)/calculator.cpp

clean:
	rm -rf $(OUTDIR)