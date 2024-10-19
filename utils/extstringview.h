#ifndef EXTSTRINGVIEW_H
#define EXTSTRINGVIEW_H

#include <string_view>
#include <set>
#include <vector>

class ExtStringView
{
public:
    ExtStringView();

    static size_t split(const std::string_view &sv,
                        const std::string_view &delimiter,
                        std::set<std::string_view> &target);
    static size_t split(const std::string_view &sv,
                        const std::string_view &delimiter,
                        std::vector<std::string_view> &target);
};

#endif // EXTSTRINGVIEW_H
