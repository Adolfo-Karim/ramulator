#ifndef __REQUEST_H
#define __REQUEST_H

#include <vector>
#include <functional>

using namespace std;

namespace ramulator
{

class Request
{
public:
    bool is_first_command;
    long addr;
    // long addr_row;
    vector<int> addr_vec;
    // specify which core this request sent from, for virtual address translation
    int coreid;
    // Specify whether the request uses processing-in-memory.
    bool in_mem;

    enum class Type
    {
        READ,
        WRITE,
        REFRESH,
        POWERDOWN,
        SELFREFRESH,
        EXTENSION,
        MAX
    } type;

    long arrive = -1;
    long depart;
    function<void(Request&)> callback; // call back with more info

    Request(long addr, Type type, bool in_mem = false, int coreid = 0)
        : is_first_command(true), addr(addr), coreid(coreid), in_mem(in_mem), type(type),
      callback([](Request& req){}) {}

    Request(long addr, Type type, function<void(Request&)> callback, bool in_mem = false, int coreid = 0)
        : is_first_command(true), addr(addr), coreid(coreid), in_mem(in_mem), type(type), callback(callback) {}

    Request(vector<int>& addr_vec, Type type, function<void(Request&)> callback, bool in_mem = false, int coreid = 0)
        : is_first_command(true), addr_vec(addr_vec), coreid(coreid), in_mem(in_mem), type(type), callback(callback) {}

    Request()
        : is_first_command(true), coreid(0) {}
};

} /*namespace ramulator*/

#endif /*__REQUEST_H*/

