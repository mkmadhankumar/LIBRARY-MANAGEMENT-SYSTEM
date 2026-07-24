CC      = gcc
CFLAGS  = -Wall -Wextra -g
TARGET  = library

SRCS = main.c \
       book_add.c \
       book_show.c \
       book_delete.c \
       book_update.c \
       book_search.c \
       book_issue.c \
       book_return.c \
       issued_list.c \
       save_file.c \
       load_file.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

%.o: %.c library.h
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all run clean
