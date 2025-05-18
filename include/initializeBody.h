#pragma once

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include "body.h"
#include "vector2.h"

std::vector<body> initializeBodies(const std::string &filename, float scale = 1e-9, float radiusScale = 1e-8);