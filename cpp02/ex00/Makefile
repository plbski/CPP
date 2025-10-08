NAME = FixePoint
CPP = g++
SRC =	main.cpp Fixed.cpp

FLAGS = -Wall -Werror -Wextra -g -std=c++98

OBJDIR = objet
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(OBJ)

$(OBJDIR)/%.o:%.cpp | $(OBJDIR)
	@$(CPP) $(FLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re