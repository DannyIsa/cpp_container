# MyContainer

A C++ template container with 6 different iteration orders (ascending, descending, side-cross, reverse, original, middle-out).
Works with any comparable type like int, string, float, etc.

## Quick Examples

### Integer Container
```cpp
MyContainer<int> container;
container.addElement(7);
container.addElement(15);
container.addElement(6);

// Print: [7, 15, 6]
std::cout << container << std::endl;

// Ascending: 6 7 15
for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
    std::cout << *it << " ";
}
```

### String Container
```cpp
MyContainer<std::string> words;
words.addElement("hello");
words.addElement("world");

// Print: [hello, world]
std::cout << words << std::endl;

// Ascending: hello world
for (auto it = words.begin_ascending_order(); it != words.end_ascending_order(); ++it) {
    std::cout << *it << " ";
}
```

## How to Run

```bash
make Main      # Run demo
make test      # Run tests
make valgrind  # Run Valgrind
make clean     # Clean files
```
