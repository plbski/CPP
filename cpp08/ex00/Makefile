# Nom de l'exécutable
NAME	= finder

# Compilateur & flags
CPP 	= g++
FLAGS	= -Wall -Werror -Wextra -g -std=c++98

# Dossiers
SRC_DIR = src
OBJ_DIR = objet

# Sources (toutes dans src/)
SRC 	= $(wildcard $(SRC_DIR)/*.cpp)

# Objets (miroir de src/ dans objet/)
OBJ 	= $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# (Optionnel) En-têtes
# INC_DIR = include
# FLAGS  += -I $(INC_DIR)

# Règles
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

# Règle générique : compile chaque .cpp de src/ en .o dans objet/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
