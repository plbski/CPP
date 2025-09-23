NAME = phone
CPP = g++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Contact.cpp PhoneBook.cpp main.cpp
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