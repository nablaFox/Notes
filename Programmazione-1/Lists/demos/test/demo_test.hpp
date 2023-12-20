#pragma once

#include "../../list.hpp"
#include "demo_list.hpp"

custom get_user_data();
custom get_random_data();
const char* get_menu(const char* filename);
void init_list(list::Node*& list, int size);
void app(list::Node*& list, int argc, char** argv);
