
#                   _           __ _ _                     _
#   _ __ ___   __ _| | _____   / _(_) | ___   ___  ___    | | ___  _ __   __ _
#  | '_ ` _ \ / _` | |/ / _ \ | |_| | |/ _ \ / __|/ _ \   | |/ _ \| '_ \ / _` |
#  | | | | | | (_| |   <  __/ |  _| | |  __/ \__ \ (_) |  | | (_) | | | | (_| |
#  |_| |_| |_|\__,_|_|\_\___| |_| |_|_|\___| |___/\___/___|_|\___/|_| |_|\__, |
#                                                    |_____|             |___/

V_CC := @echo "Building $@..."; $(CC)
AT := @
CC := gcc
EXEC	:= so_long
DIR_SRCS := srcs
FLAGS	:= -Wall -Werror -Wextra
DIR_OBJS := objs
DIR_INCS := minilibx-linux 
DIR_LIBFT:= libft

SRCS = $(addprefix $(DIR_SRCS)/,$(C_FILES))
OBJS = $(addprefix $(DIR_OBJS)/,$(O_FILES))
INCS = $(addprefix $(DIR_INCS)/,$(INCLUDES))

C_FILES	:= main.c \

O_FILES := $(C_FILES:.c=.o)
LIBFT := $(DIR_LIBFT)/libft.a
INCLUDES := mlx.h 

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

all: $(EXEC) 

$(EXEC): $(LIBFT) $(OBJS)
#	echo creating executable	
	gcc -o $(EXEC) $(OBJS) -Lminilibx-linux/ -lmlx -L/usr/include/ -L/usr/lib -lXext -lX11 -lm -lbsd
	@printf "$(ERASE)$(ERASE)$(BLUE)> Creating:$(BOLD)$(CYAN) $@ $(END)\n"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c Makefile | $(DIR_OBJS)
	gcc -I/usr/include -O3 -Iminilibx-linux/ -g -c -o $@ $< 
	@printf "$(ERASE)$(ERASE)$(BLUE)> Creating:$(RED) $@ $(END)\n"

$(DIR_OBJS):
	$(AT) mkdir -p $@ 
$(LIBFT): libft/Makefile libft/srcs/* libft/includes/libft.h
	 $(AT) $(MAKE) -C $(DIR_LIBFT)
	
clean:
	@echo Removing object files
	$(AT) $(MAKE) -C $(DIR_LIBFT) clean
	$(AT)-rm -rf $(DIR_OBJS)	 
fclean: clean
	@echo Removing application
	$(AT)-rm -f $(EXEC)
	$(AT) $(MAKE) -C $(DIR_LIBFT) fclean
	@printf "$(ERASE)$(ERASE)$(BLUE)> Deleted : $(RED)$(EXEC)$(END)\n"

re: fclean all	

.PHONY: all clean fclean
.DEFAULT: all
