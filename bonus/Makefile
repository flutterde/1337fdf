CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf  
BHEADERS = ./fdf_bonus.h ./data_types_bonus.h 
BSRCS = ./main_bonus.c ./map/map_dimensions_bonus.c ./utils/ft_exit_bonus.c \
./utils/split_w_bonus.c ./map/load_map_bonus.c \
./map/ft_free_map_bonus.c ./map/iso_dimensions_bonus.c  ./utils/hexa2int_bonus.c \
./src/fdf_key_hooks_bonus.c ./src/fdf_render_bonus.c ./src/fdf_put_pixel_bonus.c \
./src/fdf_dda_bonus.c ./src/gradient_color_bonus.c ./map/rotation_matrices_bonus.c ./src/fdf_clear_bonus.c \
./src/fdf_sidebare_bonus.c ./src/fdf_parallel_bonus.c ./src/fdf_zoomfc.c \



INCLUDES = ../MLX42/build/libmlx42.a ../libft/libft.a  ../MLX42/build/libglfw3.a -Iinclude -lm -framework Cocoa -framework OpenGL -framework IOKit

NAME = ../fdf_bonus
B_OBJS = $(BSRCS:.c=.o)


all : $(NAME)
	

$(NAME) : $(B_OBJS)
		@make -C ../libft/
		$(CC) $(CFLAGS) $(INCLUDES) $(B_OBJS) -o $(NAME)

clean :
	@$(RM) $(B_OBJS) 

%.o : %.c $(BHEADERS) 
	$(CC) $(CFLAGS) -c $< -o $@ 

fclean : clean 
		@$(RM) $(NAME) 

re : fclean all 