# Nom de la bibliothèque
NOM = libmlx.a

# Fichiers sources
SRC = mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC += mlx_png.c mlx_mouse.m

# Fichiers objets
OBJ1 = $(SRC:.c=.o)
OBJ = $(OBJ1:.m=.o)

# Flags de compilation
CFLAGS += -O2 -DSTRINGPUTX11 -DGL_SILENCE_DEPRECATION -Wno-deprecated-declarations

# Règle principale
all: $(NOM)

# Création de la bibliothèque
$(NOM): $(OBJ)
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)

# Compilation des fichiers .c en fichiers .o
%.o: %.c
	@cc $(CFLAGS) -c $< -o $@ 2>/dev/null

# Compilation des fichiers .m en fichiers .o
%.o: %.m
	@cc $(CFLAGS) -c $< -o $@ 2>/dev/null

# Nettoyage
clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app

# Recompilation complète
re: clean all
