SDIR	=	src
SRCS	=

ODIR	=	obj
OBJS	=	$(addprefix $(ODIR)/,$(SRCS:.c=.o))

IDIR	=	inc
INCL	=
HEADER	=	$(addprefix $(IDIR)/,$(INCL)) libft/inc/libft.h
INCLUDE	=	-I$(IDIR) -Ilibft/inc

LIBS	=	-Llibft/lib -lft

NAME	=	push_swap
CC		=	cc
RM		=	rm -rf
CFLAGS	=	-Wall -Wextra -Werror
OUTPUT	=	./

# ----------------Colors------------------------------------------------------
BLUE	=	\033[0;34m
CYAN	=	\033[0;36m
GREEN	=	\033[0;32m
YELLOW	=	\033[1;33m
CLEAR	=	\033[m
# ----------------------------------------------------------------------------

all: $(NAME)

$(ODIR)/%.o: $(SDIR)/%.c $(HEADER)
	@mkdir -p $(@D)
	@echo "$(BLUE)Compiling $(GREEN)$(basename $(@F))$(CLEAR)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	@make -C libft
	@mkdir -p $(OUTPUT)
	@echo "$(CYAN)Creating  $(YELLOW)push_swap ...$(CLEAR)"
	@$(CC) $(OBJS) $(LIBS) -o $(OUTPUT)/$(NAME)

clean:
	@make -C libft clean
	@$(RM) $(OBJS) $(ODIR)

fclean: clean
	@make -C libft fclean
	@$(RM) $(OUTPUT)/$(NAME)

re: fclean all

.PHONY: all clean fclean re