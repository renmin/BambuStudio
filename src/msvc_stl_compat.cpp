#ifdef _MSC_VER

#include <cstddef>
#include <cstdint>

extern "C" const unsigned long long* __std_min_element_8u(
    const unsigned long long* first,
    const unsigned long long* last)
{
    if (first == last)
        return last;

    const unsigned long long* best = first;
    for (++first; first != last; ++first) {
        if (*first < *best)
            best = first;
    }
    return best;
}

extern "C" unsigned long long* __std_unique_8(
    unsigned long long* first,
    unsigned long long* last)
{
    if (first == last)
        return last;

    unsigned long long* result = first;
    while (++first != last) {
        if (!(*result == *first))
            *++result = *first;
    }
    return ++result;
}

static bool contains_1(const unsigned char* values, std::size_t values_size, unsigned char value)
{
    for (std::size_t i = 0; i < values_size; ++i) {
        if (values[i] == value)
            return true;
    }
    return false;
}

static bool contains_2(const unsigned short* values, std::size_t values_size, unsigned short value)
{
    for (std::size_t i = 0; i < values_size; ++i) {
        if (values[i] == value)
            return true;
    }
    return false;
}

extern "C" std::size_t __std_find_first_not_of_trivial_pos_1(
    const unsigned char* first,
    std::size_t first_size,
    const unsigned char* values,
    std::size_t values_size)
{
    for (std::size_t i = 0; i < first_size; ++i) {
        if (!contains_1(values, values_size, first[i]))
            return i;
    }
    return first_size;
}

extern "C" std::size_t __std_find_last_not_of_trivial_pos_1(
    const unsigned char* first,
    std::size_t first_size,
    const unsigned char* values,
    std::size_t values_size)
{
    for (std::size_t i = first_size; i > 0; --i) {
        if (!contains_1(values, values_size, first[i - 1]))
            return i - 1;
    }
    return static_cast<std::size_t>(-1);
}

extern "C" std::size_t __std_find_first_not_of_trivial_pos_2(
    const unsigned short* first,
    std::size_t first_size,
    const unsigned short* values,
    std::size_t values_size)
{
    for (std::size_t i = 0; i < first_size; ++i) {
        if (!contains_2(values, values_size, first[i]))
            return i;
    }
    return first_size;
}

extern "C" std::size_t __std_find_last_not_of_trivial_pos_2(
    const unsigned short* first,
    std::size_t first_size,
    const unsigned short* values,
    std::size_t values_size)
{
    for (std::size_t i = first_size; i > 0; --i) {
        if (!contains_2(values, values_size, first[i - 1]))
            return i - 1;
    }
    return static_cast<std::size_t>(-1);
}

#endif
