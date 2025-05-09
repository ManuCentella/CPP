# Nombre del ejecutable
NAME = bank

# Archivos fuente
SRCS = Account.cpp tests.cpp

# Objetos
OBJS = $(SRCS:.cpp=.o)

# Compilador y flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Regla por defecto
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Limpia archivos .o
clean:
	rm -f $(OBJS)

# Limpia archivos .o y el ejecutable
fclean: clean
	rm -f $(NAME)

# Recompila todo desde cero
re: fclean all

# Objetivo phony para evitar conflictos con archivos
.PHONY: all clean fclean re
