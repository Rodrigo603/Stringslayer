# Nome do executável
TARGET = build/stringslayer

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Diretórios
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Todos os arquivos .c em src/
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Constrói os arquivos .o no diretório build/
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Bibliotecas Raylib e do sistema
LIBS = -lraylib -lm -ldl -lpthread -lGL -lrt -lX11

# Regra padrão
all: $(TARGET)

# Compila cada .c para .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link final
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LIBS)

# Executa o programa
run: $(TARGET)
	./$(TARGET)

# Remove arquivos gerados
clean:
	rm -rf $(BUILD_DIR)

# Faz tudo de novo
rebuild: clean all