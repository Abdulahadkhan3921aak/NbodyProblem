# Compiler configuration
CC := g++
CFLAGS := -DGLEW_STATIC
INCLUDES := -Iinclude -IDependencies/GLEW/include -IDependencies/GLFW/include
LDFLAGS := -LDependencies/GLEW/lib/Release/Win32 -LDependencies/GLFW/lib
LIBS := -lglew32 -lglfw3 -lopengl32 -lgdi32

# File locations
SRCDIR := src
BUILDDIR := build
OBJDIR := $(BUILDDIR)/obj
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))
TARGET := $(BUILDDIR)/Nbody.exe

# Convert paths to Windows-style
WIN_BUILDDIR := $(subst /,\,$(BUILDDIR))
WIN_OBJDIR := $(subst /,\,$(OBJDIR))

# Build rules
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo Linking $@...
	@$(CC) $(LDFLAGS) $^ $(LIBS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | dirs
	@echo Compiling $<...
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

dirs:
	@if not exist "$(WIN_BUILDDIR)" mkdir "$(WIN_BUILDDIR)"
	@if not exist "$(WIN_OBJDIR)" mkdir "$(WIN_OBJDIR)"

run: all
	@echo Running $(TARGET)...
	@$(TARGET)

clean:
	@echo Cleaning object files...
	@if exist "$(WIN_OBJDIR)" del /Q "$(WIN_OBJDIR)\*.o" 2> nul

hclean:
	@echo Performing hard clean...
	@if exist "$(WIN_BUILDDIR)" rmdir /S /Q "$(WIN_BUILDDIR)" 2> nul

.PHONY: all run clean hclean dirs