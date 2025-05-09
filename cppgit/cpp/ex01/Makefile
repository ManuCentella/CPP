# Nombre del ejecutable
NAME = phonebook

# Compilador y flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Archivos fuente
SRCS = main.cpp PhoneBook.cpp Contact.cpp

# Archivos objeto
OBJS = $(SRCS:.cpp=.o)

# Regla principal
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Limpiar archivos .o
clean:
	rm -f $(OBJS)

# Limpiar ejecutable y .o
fclean: clean
	rm -f $(NAME)

# Recompilar desde cero
re: fclean all

# Regla por defecto
.PHONY: all clean fclean re
