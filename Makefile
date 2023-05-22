#Compiler settings
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++17
LDFLAGS = -lncurses

#Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

#Create executable file
$(BINDIR)/network: $(OBJDIR)/Main.o $(OBJDIR)/Network.o $(OBJDIR)/Layer.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

#Create Main object file
$(OBJDIR)/Main.o: $(SRCDIR)/Main.c++ $(SRCDIR)/Main.h
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -c $< -o $@

#Create Network object file
$(OBJDIR)/Network.o: $(SRCDIR)/Network.c++ $(SRCDIR)/Main.h 
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -c $< -o $@

#Create Layer bject file
$(OBJDIR)/Layer.o: $(SRCDIR)/Layer.c++ $(SRCDIR)/Main.h 
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) -c $< -o $@


#Remove all execuable and object files
clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/game

#Run Main execuable file
exec: $(BINDIR)/network
	$(BINDIR)/network