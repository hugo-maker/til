CFLAGS=-g -O3 -Wall -Wextra -Isrc $(shell pkg-config --cflags libbsd) -rdynamic -DNDEBUG -lm $(OPTFLAGS)
COMMON_LIBS= $(shell pkg-config --libs libbsd) -ldl $(OPTLIBS)
LDLIBS=$(COMMON_LIBS)
PREFIX?=/usr/local

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))

PROGRAMS_SRC=$(wildcard bin/*.c)
PROGRAMS=$(patsubst %.c,%,$(PROGRAMS_SRC))

TARGET=build/liblcthw.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# The TARGET Build
all: $(TARGET) $(SO_TARGET) tests $(PROGRAMS)

dev: CFLAGS=-g -Wall -Wextra -Isrc -lm $(shell pkg-config --clags libbsd) $(OPTFLAGS)
dev: all

$(TESTS): $(TARGET) $(SO_TARGET) -ldl -lm

# PROGRAMS
$(PROGRAMS): CFLAGS += $(TARGET)

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@
$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

build:
	@mkdir -p build
	@mkdir -p bin

# The Unit Tests
.PHONY: tests
test: LDLIBS = $(TARGET) $(COMMON_LIBS)
tests: $(TESTS)
	sh ./tests/runtests.sh

# The Cleaner
clean:
	rm -rf build $(OBJECTS) $(TESTS) $(PROGRAMS)
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`

# The Install
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

# The Checker
check:
	@echo Files with potentially dangerous functions.
	@egrep '[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)\
				|stpn?cpy|a?sn?printf|byte_)' $(SOURCES) || true
