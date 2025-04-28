CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
OBJS = $(OBJDIR)/InOrderTraverse.o $(OBJDIR)/Search.o $(OBJDIR)/DeleteFixup.o $(OBJDIR)/Maximum.o $(OBJDIR)/Delete.o $(OBJDIR)/Shift.o $(OBJDIR)/Minimum.o $(OBJDIR)/RightRotate.o $(OBJDIR)/LeftRotate.o $(OBJDIR)/main.o $(OBJDIR)/RBLocateParent.o $(OBJDIR)/RBTreeInsert.o $(OBJDIR)/Sibling.o $(OBJDIR)/RBInsertFixupA.o $(OBJDIR)/RBInsertFixupB.o $(OBJDIR)/RBInsertFixupC.o $(OBJDIR)/PrintTree.o
OBJDIR = object_files
TARGET = rbtree

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp rbtree.h | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(OBJS) $(TARGET)

zip:
	zip -r red-black-tree.zip *.cpp *.h Makefile CSE2331FinalProject.pdf