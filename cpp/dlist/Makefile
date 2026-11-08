# ---------- compiler & flags ----------
CXX           = g++
CXXFLAGS      = -std=c++98 -pedantic-errors -Wall -Wextra -fPIC
DEBUG_FLAGS   = -g
RELEASE_FLAGS = -O3 -DNDEBUG

# ---------- names ----------
NAME = dlist
LIB  = lib$(NAME).so
TEST = $(NAME)_test.out

# ---------- files ----------
LIB_OBJS  = $(NAME).o
TEST_OBJS = $(NAME)_test.o
DEPS      = $(LIB_OBJS:.o=.d) $(TEST_OBJS:.o=.d)

.PHONY: all test debug release clean

# ---------- default: build everything ----------
all: $(LIB) $(TEST)

# ---------- shared object ----------
$(LIB): $(LIB_OBJS)
	$(CXX) -shared $^ -o $@

# ---------- test executable, linked to the .so ----------
$(TEST): $(TEST_OBJS) $(LIB)
	$(CXX) $(TEST_OBJS) -L. -Wl,--no-as-needed -l$(NAME) -Wl,-rpath,'$$ORIGIN' -o $@

# ---------- compile any .cpp to .o (+ .d dependency file) ----------
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# ---------- phony targets ----------
test: $(TEST)
	./$(TEST)

debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: all

release: CXXFLAGS += $(RELEASE_FLAGS)
release: all

clean:
	rm -f $(LIB_OBJS) $(TEST_OBJS) $(DEPS) $(LIB) $(TEST)

# ---------- auto-generated header dependencies ----------
-include $(DEPS)
