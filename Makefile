
#                   _           __ _ _                     _
#   _ __ ___   __ _| | _____   / _(_) | ___   ___  ___    | | ___  _ __   __ _
#  | '_ ` _ \ / _` | |/ / _ \ | |_| | |/ _ \ / __|/ _ \   | |/ _ \| '_ \ / _` |
#  | | | | | | (_| |   <  __/ |  _| | |  __/ \__ \ (_) |  | | (_) | | | | (_| |
#  |_| |_| |_|\__,_|_|\_\___| |_| |_|_|\___| |___/\___/___|_|\___/|_| |_|\__, |
#                                                    |_____|             |___/

# ─── VARIABLES ──────────────────────────────────────────────────────────────────
	
V_CC := @echo "Building $@..."; $(CC)
AT := @
CC := gcc
CNAME := $(shell uname -s)
EXEC		:= so_long
EXEC_FLAGS_MAC = -Lmlx -lmlx -framework OpenGL -framework AppKit 
OBJS_FLAGS_MAC = -Imlx -Iincludes 
EXEC_FLAGS_LINUX := linux_mlx/libmlx.a -L/usr/include/ -L/usr/lib  -lXext -lX11 -lm -lbsd
OBJS_FLAGS_LINUX := -I/usr/include -lmlx -O3 -Iincludes -Ilinux_mlx -Llinux_mlx
DIR_SRCS	:= srcs
FLAGS		:= -g -Wall -Werror -Wextra
DIR_OBJS	:= objs
DIR_INCS	:= includes
DIR_LIBFT	:= libft
DIR_GNL		:= gnl
FILE_INCS	:= so_long.h
SRCS = $(addprefix $(DIR_SRCS)/,$(C_FILES))
OBJS = $(addprefix $(DIR_OBJS)/,$(O_FILES))
INCS = $(addprefix $(DIR_INCS)/,$(FILE_INCS))
LIBFT := $(DIR_LIBFT)/libft.a
GNL	:= $(DIR_GNL)/gnl.a
O_FILES = $(C_FILES:.c=.o)
C_FILES	:= so_long.c parsing.c error.c game.c \

ifeq ($(CNAME), Linux)
EXEC_FLAGS_MAC = $(EXEC_FLAGS_LINUX)
OBJS_FLAGS_MAC = $(OBJS_FLAGS_LINUX)
endif



# ─── COLORS ─────────────────────────────────────────────────────────────────────
	
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

# ─── RULES ──────────────────────────────────────────────────────────────────────
	
all: libft gnl $(EXEC) 

$(EXEC): $(LIBFT) $(GNL) $(OBJS) $(INCS)
	$(AT) $(CC)  $(OBJS) $(LIBFT) $(GNL) $< -o $(EXEC) $(EXEC_FLAGS_MAC) 
	@printf "$(ERASE)$(ERASE)$(BLUE)> Creating:$(BOLD)$(CYAN) $@ $(END)\n"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c Makefile $(INCS) | $(DIR_OBJS)
	$(AT) $(CC) $(FLAGS) $(OBJS_FLAGS_MAC) -c $< -o $@ 
	@printf "$(ERASE)$(ERASE)$(BLUE)> Creating:$(RED) $@ $(END)\n"

$(DIR_OBJS):
	$(AT) mkdir -p $@ 

$(LIBFT):libft 

$(GNL):gnl

libft:
	$(AT) $(MAKE) -C $(DIR_LIBFT)
gnl:
	$(AT) $(MAKE) -C $(DIR_GNL)
	
clean:
	@echo Removing object files
	$(AT) $(MAKE) -C $(DIR_LIBFT) clean
	$(AT) $(MAKE) -C $(DIR_GNL) clean
	$(AT)-rm -rf $(DIR_OBJS)	 
fclean: clean
	@echo Removing application
	$(AT)-rm -f $(EXEC)
	$(AT) $(MAKE) -C $(DIR_LIBFT) fclean
	$(AT) $(MAKE) -C $(DIR_GNL) fclean
	@printf "$(ERASE)$(ERASE)$(BLUE)> Deleted : $(RED)$(EXEC)$(END)\n"

re: fclean all	

.PHONY: all clean fclean libft gnl
.DEFAULT: all
