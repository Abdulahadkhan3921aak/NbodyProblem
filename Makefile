# -------------------------------------------------------------------
# Cross‑Platform Makefile for N‑Body Project
# -------------------------------------------------------------------

# --- Compiler configuration ---
CC       := g++
CFLAGS   := -DGLEW_STATIC
INCLUDES := -Iinclude -IDependencies/GLEW/include -IDependencies/GLFW/include
LDFLAGS  := -LDependencies/GLEW/lib/Release/Win32 -LDependencies/GLFW/lib
LIBS     := -lglew32 -lglfw3 -lopengl32 -lgdi32

# --- File layout ---
SRCDIR    := src
BUILDDIR  := build
OBJDIR    := $(BUILDDIR)/obj
SOURCES   := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS   := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))
TARGET    := $(BUILDDIR)/Nbody.exe

# Windows‑style paths (for cmd)
WIN_BUILDDIR := $(subst /,\,$(BUILDDIR))
WIN_OBJDIR   := $(subst /,\,$(OBJDIR))

# Detect whether MAKE is running under Windows cmd (OS=Windows_NT)
IS_WINDOWS := $(findstring Windows_NT,$(OS))

# -------------------------------------------------------------------
# Platform‑specific helper macros
# -------------------------------------------------------------------
ifeq ($(IS_WINDOWS),Windows_NT)
  # On cmd.exe:
  MKDIR = if not exist "$(subst /,\,$1)" mkdir "$(subst /,\,$1)"
  RMDIR = if exist "$(subst /,\,$1)" rmdir /S /Q "$(subst /,\,$1)"
  DEL   = if exist "$(subst /,\,$1)\*.o" del /Q "$(subst /,\,$1)\*.o"
else
  # On sh‑style shell:
  MKDIR = mkdir -p $1
  RMDIR = rm -rf $1
  DEL   = rm -f $1/*.o
endif

# -------------------------------------------------------------------
# Build targets
# -------------------------------------------------------------------

.PHONY: all dirs run clean hclean

all: dirs $(TARGET)

$(TARGET): $(OBJECTS)
	@echo Linking $@...
	@$(CC) $(LDFLAGS) $^ $(LIBS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo Compiling $<...
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create build directories
dirs:
	@$(call MKDIR,$(BUILDDIR))
	@$(call MKDIR,$(OBJDIR))

# Run the built executable
run: all
	@echo Running $(TARGET)...
	@"$(TARGET)"

# Remove object files only
clean:
	@echo Cleaning object files...
	@$(call DEL,$(OBJDIR))

# Remove entire build directory
hclean:
	@echo Performing hard clean...
	@$(call RMDIR,$(BUILDDIR))
