AT = @
LIBRARY		= ft_printf.a
DIR_SRCS	:= srcs
FLAGS		:= -g -Wall -Werror -Wextra
DIR_OBJS	:= objs
DIR_INCS	:= includes
INCLUDES	 = ft_printf.h 

SRCS = $(addprefix $(DIR_SRCS)/,$(C_FILES))
OBJS = $(addprefix $(DIR_OBJS)/,$(O_FILES))
INCS = $(addprefix $(DIR_INCS)/,$(INCLUDES))

C_FILES =	ft_printf.c ft_putnbr_base.c ft_strchr.c \
			tools.c	ft_print_address.c \

O_FILES = $(C_FILES:.c=.o)

ERASE	=	\033[2K\r
GREY	=	\033[30m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
PINK	=	\033[35m
CYAN	=	\033[36m
WHITE	=	\033[37m
BOLD	=	\033[1m
UNDER	=	\033[4m
SUR		=	\033[7m
END		=	\033[0m

all: $(LIBRARY) 

$(LIBRARY): $(OBJS) $(INCS)
	$(AT) ar -rcs $(LIBRARY) $(OBJS)
	$(AT) ranlib $(LIBRARY)
	@printf "$(ERASE)$(ERASE)$(BLUE)> Creating:$(BOLD)$(CYAN) $@ $(END)\n"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(INCS) Makefile $(DIR_OBJS)
	$(AT) $(CC) -I $(DIR_INCS) $(FLAGS) -c  $< -o $@
	@printf "$(ERASE)$(ERASE)$(BLUE)> Creating:$(RED) $@ $(END)\n"

$(DIR_OBJS):
	$(AT) mkdir -p $@ 
	
clean:
	@echo Removing object files
	$(AT)-rm -rf $(DIR_OBJS)
fclean: clean
	@echo Removing application
	$(AT)-rm -f $(LIBRARY)

re: fclean all	

.PHONY: all clean fclean
.DEFAULT: all
