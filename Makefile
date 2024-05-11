CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf  
HEADERS = ./mandatory/fdf.h ./mandatory/data_types.h 
SRCS = ./mandatory/main.c ./mandatory/map/map_dimensions.c ./mandatory/utils/ft_exit.c \
./mandatory/utils/split_w.c ./mandatory/map/load_map.c \
./mandatory/map/ft_free_map.c ./mandatory/map/iso_dimensions.c  ./mandatory/utils/hexa2int.c \
./mandatory/src/fdf_key_hooks.c ./mandatory/src/fdf_render.c ./mandatory/src/fdf_put_pixel.c \
./mandatory/src/fdf_dda.c ./mandatory/src/gradient_color.c ./mandatory/map/rotation_matrices.c \



INCLUDES = MLX42/build/libmlx42.a libft/libft.a  MLX42/build/libglfw3.a -Iinclude -lm -framework Cocoa -framework OpenGL -framework IOKit

NAME = fdf
OBJS = $(SRCS:.c=.o)


all : $(NAME)
	

$(NAME) : $(OBJS)
		make -C libft/
		$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

bonus : 
	make bonus -C bonus/

clean :
	$(RM) $(OBJS) 

%.o : %.c $(HEADERS) 
	$(CC) $(CFLAGS) -c $< -o $@ 

fclean : clean 
		$(RM) $(NAME) 

re : fclean all 