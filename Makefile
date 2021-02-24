HEADER_DIR   := include
SOURCE_DIR   := src
OBJECT_DIR   := obj

SOURCES      := $(shell find $(SOURCE_DIR) -name "*.cxx")
OBJECTS      := $(patsubst $(SOURCE_DIR)/%.cxx, $(OBJECT_DIR)/%.o, $(SOURCES))

CXX      := g++
CXXFLAGS := -g -Wall -Wextra -Wabi -Weffc++ -Wno-reorder
CXXFLAGS += -I$(HEADER_DIR)
#CXXFLAGS += $(shell root-config --cflags)
#CXXFLAGS += $(shell yoda-config --cflags)

LIBS := -lbeetroot
LIBS += $(shell root-config --libs)
LIBS += $(shell yoda-config --libs)
LIBS += -lmgl

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.cxx
	@mkdir -p $(OBJECT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

runExamples: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)
	
clean:
	rm -rf $(OBJECT_DIR)/*.o plots/* plotsC/* runExamples
