#include <iostream>
#include <vector>

template <typename T>
class Table {
public:
    Table(size_t rows, size_t cols)
            : data(rows, std::vector<T>(cols)), numRows(rows), numCols(cols) {}

    std::vector<T>& operator[](size_t row) {
        return data[row];
    }

    const std::vector<T>& operator[](size_t row) const {
        return data[row];
    }

    std::pair<size_t, size_t> Size() const {
        return {numRows, numCols};
    }

private:
    std::vector<std::vector<T>> data;
    size_t numRows, numCols;
};

int main() {
    Table<int> test(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0] << std::endl;

    auto [rows, cols] = test.Size();
    std::cout << "Размер таблицы: " << rows << "x" << cols << std::endl;

    return 0;
}

