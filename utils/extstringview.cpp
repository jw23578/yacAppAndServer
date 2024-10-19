#include "extstringview.h"

ExtStringView::ExtStringView() {}

size_t ExtStringView::split(const std::string_view &sv,
                            const std::string_view &delimiter,
                            std::set<std::string_view> &target)
{
    size_t start(0);
    size_t p(sv.find(delimiter));
    while (p != std::string_view::npos)
    {
        target.insert(sv.substr(start, p - start));
        start = p + delimiter.size();
        p = sv.find(delimiter, start);
    }
    if (start < sv.size())
    {
        target.insert(sv.substr(start));
    }
    return target.size();
}

size_t ExtStringView::split(const std::string_view &sv,
                            const std::string_view &delimiter,
                            std::vector<std::string_view> &target)
{
    size_t start(0);
    size_t p(sv.find(delimiter));
    while (p != std::string_view::npos)
    {
        target.push_back(sv.substr(start, p - start));
        start = p + delimiter.size();
        p = sv.find(delimiter, start);
    }
    if (start < sv.size())
    {
        target.push_back(sv.substr(start));
    }
    return target.size();
}
