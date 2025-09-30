NAME = test
CPP = g++
SRC =	main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

FLAGS = -Wall -Werror -Wextra -g

OBJDIR = objet
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

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