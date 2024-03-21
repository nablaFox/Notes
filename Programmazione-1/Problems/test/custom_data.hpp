#pragma once

struct Custom {
	int a;
	int b;
};

namespace list {
typedef Custom data;
} // namespace list

namespace stack {
typedef Custom data;
const int MAX_SIZE = 10;
} // namespace stack

namespace queue {
typedef Custom data;
const int SIZE = 10;
} // namespace queue
